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
		ft_error("no such file or directory", av[1]);
	if (dup2(infd, STDIN_FILENO) == -1)
		ft_perror("dup");
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		ft_perror("dup");
	close(infd);
	exec(av[2], env);
}

void	parentp(char **av, char **env, int *fd)
{
	int		outfd;

	close(fd[1]);
	outfd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfd == -1)
		ft_error("no such file or directory", av[4]);
	if (dup2(outfd, STDOUT_FILENO) == -1)
		ft_perror("dup");
	if (dup2(fd[0], STDIN_FILENO) == -1)
		ft_perror("dup");
	close(outfd);
	exec(av[3], env);
}

int	main(int ac, char **av, char **env)
{
	int		fd[2];
	pid_t	pid;

	if (ac != 5)
		ft_error("Invalid argument", "./pipex infile cmd1 cmd2 outfile");
	if (pipe(fd) == -1)
		ft_perror("pipe");
	pid = fork();
	if (pid == -1)
		ft_perror("fork");
	if (pid == 0)
		childp(av, env, fd);
	parentp(av, env, fd);
}
