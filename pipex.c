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

char	*ft_cmdpath(char **paths, char *cmd)
{
	char	*cmdpath;
	size_t	i;

	i = 0;
	while (paths[i])
	{
		cmdpath = ft_strjoin(paths[i], cmd);
		if (!access(cmdpath, X_OK))
			return (cmdpath);
		free(cmdpath);
		i++;
	}
	return (NULL);
}

char	**ft_getpaths(char **envp)
{
	char	**paths;
	char	*line;
	size_t	i;

	i = 0;
	line = NULL;
	while (envp[i] && !line)
		line = ft_strstr(envp[i++], "PATH=");
	if (!line)
		return (NULL);
	paths = ft_split((line + 5), ':');
	if (!paths)
		return (NULL);
	i = 0;
	line = NULL;
	while (paths[i])
	{
		line = ft_strjoin(paths[i], "/");
		free(paths[i]);
		paths[i] = line;
		i++;
	}
	return (paths);
}

int	ft_scmd(char **av, char **paths,  char **env, int *fd)
{
	char	**option;
	char	*cmdpath;
	int		infd;

	printf("4\n");
	infd = open(av[1], O_RDWR | O_TRUNC);
	option = ft_split(av[2], ' ');
	cmdpath = ft_cmdpath(paths, option[0]);
	dup2(infd, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	execve(cmdpath, option, env);
	return (-1);
}

int	ft_fcmd(char **av, char **paths, char **env, int *fd)
{
	char	**option;
	char	*cmdpath;
	int		outfd;

	printf("1\n");
	outfd = open(av[4], O_WRONLY);
	option = ft_split(av[3], ' ');
	cmdpath = ft_cmdpath(paths, option[0]);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfd, STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	execve(cmdpath, option, env);
	return (-1);
}

int	ft_clearfile(char **av, char **paths, char **env, int *fd)
{
	char	**option;
	char	*cmdpath;
	int		outfd;

	printf("ICI\n");
	outfd = open(av[4], O_WRONLY);
	option = ft_split("clear", ' ');
	cmdpath = ft_cmdpath(paths, option[0]);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfd, STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	execve(cmdpath, option, env);
	return (-1);
}

int	main(int ac, char **av, char **env)
{
	char	**paths;
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (ac != 5 || pipe(fd) == -1)
		return (-1);
	paths = ft_getpaths(env);
	pid1 = fork();
	pid2 = fork();
	if (pid1 < 0 || pid2 < 0)
		return (-1);
	if (pid1 > 0 && pid2 > 0)
		return(ft_fcmd(av, paths, env, fd));
	if (pid1 > 0 && pid2 == 0)
		return(ft_clearfile(av, paths, env, fd));// clear outfile ?
	if (pid1 == 0 && pid2 > 0)
		ft_scmd(av, paths, env, fd);
	if (pid1 == 0 && pid2 == 0)
		return (-1);
	printf("4\n");// close all files ?
	close(fd[0]);
	close(fd[1]);
	ft_freetab(paths);
	waitpid(pid2, NULL, WUNTRACED);
	waitpid(pid1, NULL, WUNTRACED);
	system("leaks pipex");
	return (0);
}
