/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:57:02 by blaurent          #+#    #+#             */
/*   Updated: 2022/07/01 11:57:02 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

void exec(char *av, char **env)
{
	char	**paths;
	char	**option;
	char	*cmdpath;

	paths = ft_getpaths(env);
	option = ft_split(av, ' ');
	cmdpath = ft_cmdpath(paths, option[0]);
	if (!cmdpath)
	{
		ft_freetab(option);
		free(cmdpath);
		error();
	}
	if (execve(cmdpath, option, env) == -1)
		exit(EXIT_FAILURE);
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
		{
			ft_freetab(paths);
			return (cmdpath);
		}
		free(cmdpath);
		i++;
	}
	ft_freetab(paths);
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