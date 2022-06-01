/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:54:05 by blaurent          #+#    #+#             */
/*   Updated: 2022/06/01 14:20:08 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_freetab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

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

void	ft_son(char **av, char **paths,int *fd)
{
	char	**option;
	char	*cmdpath;
	int		infd;

	infd = open(av[1], O_RDONLY);
	option = ft_split(av[2], ' ');
	cmdpath = ft_cmdpath(paths, option[0]);
	dup2(infd, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	execve(cmdpath, option, NULL);
}

void	ft_daddy(char **av, char **paths,int *fd)
{
	char	**option;
	char	*cmdpath;
	int		outfd;

	outfd = open(av[4], O_WRONLY);
	option = ft_split(av[3], ' ');
	cmdpath = ft_cmdpath(paths, option[0]);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfd, STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	execve(cmdpath, option, NULL);
}

int	main(int ac, char **av, char **env)
{
	char	**paths;
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		return (-1);
	paths = ft_getpaths(env);
	pid = fork();
	if (pid < 0)
		return (-1);
	else if (pid == 0)
		ft_daddy(av, paths, fd);
	else if (pid > 0)
		ft_son(av, paths, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid, NULL, WUNTRACED);
	ft_freetab(paths);
	// system("leaks a.out");
	return (0);
}
