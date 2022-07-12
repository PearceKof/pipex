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
	infd = open(av[1], O_RDONLY, 0777);
	if (infd == -1)
		ft_error(NULL, av[1], EXIT_FAILURE);
	if (dup2(infd, STDIN_FILENO) == -1)
		ft_error(NULL, "dup", EXIT_FAILURE);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		ft_error(NULL, "dup", EXIT_FAILURE);
	close(infd);
	exec(av[2], env, EXIT_FAILURE);
}

void	parentp(char **av, char **env, int *fd, int status)
{
	int		outfd;

	close(fd[1]);
	outfd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfd == -1)
		ft_error(NULL, av[4], WEXITSTATUS(status));
	if (dup2(outfd, STDOUT_FILENO) == -1)
		ft_error(NULL, "dup", WEXITSTATUS(status));
	if (dup2(fd[0], STDIN_FILENO) == -1)
		ft_error(NULL, "dup", WEXITSTATUS(status));
	close(outfd);
	exec(av[3], env, WEXITSTATUS(status));
}

int	main(int ac, char **av, char **env)
{
	int		status;
	int		fd[2];
	pid_t	pid;

	if (ac != 5)
		ft_error("Invalid argument", "./pipex infile cmd1 cmd2 outfile", 1);
	if (pipe(fd) == -1)
		ft_error(NULL, "pipe", EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		ft_error(NULL, "fork", EXIT_FAILURE);
	if (pid == 0)
		childp(av, env, fd);
	waitpid(pid, &status, WNOHANG);
	parentp(av, env, fd, status);
}
