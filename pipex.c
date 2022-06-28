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
	char	**option;
	char	*cmdpath;
	int		infd;

	infd = open(av[1], O_RDWR);
	if (infd == -1)
		error();
	option = ft_split(av[2], ' ');
	cmdpath = ft_cmdpath(paths, option[0]);
	dup2(infd, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	execve(cmdpath, option, env);
}

void	ft_daddy(char **av, char **env, int *fd)
{
	char	**option;
	char	*cmdpath;
	int		outfd;

	outfd = open(av[4], O_WRONLY | O_CREAT | O_WRONLY | O_TRUNC);
	if (outfd == -1)
		error();
	option = ft_split(av[3], ' ');
	cmdpath = ft_cmdpath(paths, option[0]);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfd, STDOUT_FILENO);
	close(fd[1]);
	execve(cmdpath, option, env);
}

// int	ft_clearfile(char **av, char **paths, char **env, int *fd)
// {
// 	char	**option;
// 	char	*cmdpath;
// 	int		outfd;

// 	outfd = open(av[4], O_WRONLY);
// 	option = ft_split("clear", ' ');
// 	cmdpath = ft_cmdpath(paths, option[0]);
// 	dup2(fd[0], STDIN_FILENO);
// 	dup2(outfd, STDOUT_FILENO);
// 	close(fd[0]);
// 	close(fd[1]);
// 	execve(cmdpath, option, env);
// 	return (-1);
// }

int	main(int ac, char **av, char **env)
{
	char	**paths;
	int		fd[2];
	pid_t	pid;

	if (ac == 5)
	{
		if (pipe(fd) == -1)
			error();
		paths = ft_getpaths(env);
		pid = fork();
		if (pid == -1)
			error();
		if (pid == 0)
			ft_son(av, env, fd);
		ft_freetab(paths);
		waitpid(pid1, NULL, 0);
		ft_daddy(av, env, fd);
	}
	else
	{
		error();
	}
	system("leaks pipex");
	return (0);
}
