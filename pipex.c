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

void	childp(char **av, char **env, int *fd)
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
	exec(av[2], env, EXIT_FAILURE);
}

void	parentp(char **av, char **env, int *fd, int status)
{
	int		outfd;

	close(fd[1]);
	outfd = open(av[4], O_WRONLY | O_TRUNC | O_CREAT, 00777);
	if (outfd == -1)
		ft_error(av[4], NULL, EXIT_FAILURE);
	if (dup2(outfd, STDOUT_FILENO) == -1)
		ft_error("dup", NULL, WEXITSTATUS(status));
	close(outfd);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		ft_error("dup", NULL, WEXITSTATUS(status));
	close(fd[0]);
	exec(av[3], env, WEXITSTATUS(status));
}

int	main(int ac, char **av, char **env)
{
	int		status;
	int		fd[2];
	pid_t	pid;

	if (ac != 5)
	{
		ft_putstr_fd("Invalid arguments\nex: ./pipex in cmd1 cmd2 out\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (pipe(fd) == -1)
		ft_error("pipe", NULL, EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		ft_error("fork", NULL, EXIT_FAILURE);
	if (pid == 0)
		childp(av, env, fd);
	if(waitpid(pid, &status, WNOHANG) == -1)
		ft_error("waitpid", NULL, EXIT_FAILURE);
	parentp(av, env, fd, status);
}
