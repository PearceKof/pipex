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

void	ft_son(char **av, char **env, int *fd)
{
	int		infd;

	close(fd[0]);
	infd = open(av[1], O_RDWR, 777);
	if (infd == -1)
		ft_error("no such file or directory", av[1]);
	dup2(fd[1], STDOUT_FILENO);
	dup2(infd, STDIN_FILENO);
	close(fd[1]);
	close(infd);
	exec(av[2], env);
}

void	ft_daddy(char **av, char **env, int *fd)
{
	int		outfd;

	close(fd[1]);
	outfd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 777);
	if (outfd == -1)
		ft_error("no such file or directory", av[4]);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfd, STDOUT_FILENO);
	close(fd[0]);
	close(outfd);
	exec(av[3], env);
}

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid;
	pid_t	pid2;

	if (ac == 5)
	{
		if (pipe(fd) == -1)
			ft_error(NULL, NULL);
		pid = fork();
		if (pid == -1)
			ft_error(NULL, NULL);
		if (pid == 0)
			ft_son(av, envp, fd);
		pid2 = fork();
		if (pid2 == -1)
			ft_error(NULL, NULL);
		if (pid2 > 0)
			ft_daddy(av, envp, fd);
		close(fd[0]);
		close(fd[1]);
		waitpid(pid, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
	else
	{
		ft_printf("number of argument different of 5");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
