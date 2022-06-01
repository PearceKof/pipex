/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:54:05 by blaurent          #+#    #+#             */
/*   Updated: 2022/05/30 16:19:23 by blaurent         ###   ########.fr       */
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
	size_t	i;
	char	**paths;
	char	*line;

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
	int		infd;
	char	**option;
	char	*cmdpath;

	cmdpath = ft_cmdpath(paths, av[1]);
	printf("%s", cmdpath);
	// dup2(infd, STDIN_FILENO);
	// dup2(fd[1], STDOUT_FILENO);
	// execve(cmdpath, option, NULL);
	// close(infd);
}

void	ft_daddy(char **av, char **paths,int *fd)
{
	int	outfd;
}

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	char	**paths;


	paths = ft_getpaths(envp);
	if (pipe(fd) == -1)
		return (-1);
	pid1 = fork();
	if (pid1 < 0)
		return (-1);
	else if (pid1 == 0)
		ft_son(av, paths, fd);
	else if (pid1 > 0)
		ft_daddy(av, envp, fd);
	waitpid(pid1, NULL, 0);
	ft_freetab(paths);
	// system("leaks a.out");
	return (0);
}
