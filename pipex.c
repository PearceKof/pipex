/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:54:05 by blaurent          #+#    #+#             */
/*   Updated: 2022/06/03 12:42:28 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	firstchild(char **av, char **env, int *fd)
{
	int		infd;

	close(fd[0]);
	infd = open(av[1], O_RDONLY);
	if (infd == -1)
		ft_error(av[1], NULL, EXIT_FAILURE);
	if (dup2(infd, STDIN_FILENO) == -1)
		ft_error("dup", NULL, EXIT_FAILURE);
	close(infd);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		ft_error("dup", NULL, EXIT_FAILURE);
	close(fd[1]);
	exec(av[2], env);
}

void	secondchild(char **av, char **env, int *fd)
{
	int		outfd;

	close(fd[1]);
	outfd = open(av[4], O_WRONLY | O_TRUNC | O_CREAT, 00777);
	if (outfd == -1)
		ft_error(av[4], NULL, EXIT_FAILURE);
	if (dup2(outfd, STDOUT_FILENO) == -1)
		ft_error("dup", NULL, EXIT_FAILURE);
	close(outfd);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		ft_error("dup", NULL, EXIT_FAILURE);
	close(fd[0]);
	exec(av[3], env);
}

int	pipex(char **av, char **env, int *fd)
{
	int		status;
	pid_t	pid1;
	pid_t	pid2;

	pid1 = fork();
	if (pid1 == -1)
		ft_error("fork", NULL, EXIT_FAILURE);
	if (pid1 == 0)
		firstchild(av, env, fd);
	pid2 = fork();
	if (pid2 == -1)
		ft_error("fork", NULL, EXIT_FAILURE);
	if (pid2 == 0)
		secondchild(av, env, fd);
	close(fd[0]);
	close(fd[1]);
	if (waitpid(pid1, NULL, 0) == -1)
		return (EXIT_FAILURE);
	if (waitpid(pid2, &status, 0) == -1)
		return (EXIT_FAILURE);
	return (WEXITSTATUS(status));
}

int	main(int ac, char **av, char **env)
{
	int		fd[2];

	if (ac != 5)
	{
		ft_putstr_fd("Invalid arguments\nex: ./pipex in cmd1 cmd2 out\n", 2);
		exit(EXIT_FAILURE);
	}
	if (pipe(fd) == -1)
		ft_error("pipe", NULL, EXIT_FAILURE);
	return (pipex(av, env, fd));
}
