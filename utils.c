/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:57:02 by blaurent          #+#    #+#             */
/*   Updated: 2022/07/01 11:57:02 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *mess, char *where, int ret)
{
	if (mess)
		ft_fprintf(STDERR_FILENO, "%s: %s\n", where, mess);
	else if (where)
		perror(where);
	exit(ret);
}

void	exec(char *av, char **env, int ret)
{
	char	**env_paths;
	char	**option;
	char	*cmdpath;

	env_paths = ft_getpaths(env);
	if (!env_paths)
		ft_error(NULL, "env", ret);
	option = ft_split(av, ' ');
	if (!option)
	{
		ft_freetab(env_paths);
		ft_error(NULL, "ft_split", ret);
	}
	cmdpath = ft_cmdpath(env_paths, option[0]);
	if (!cmdpath)
	{
		ft_freetab(option);
		ft_fprintf(STDERR_FILENO, "command not found : %d", av);
		exit(127);
	}
	if (execve(cmdpath, option, env) == -1)
	{
		ft_freetab(option);
		free(cmdpath);
		ft_error(NULL, "execve failed", 126);
	}
}

char	*ft_cmdpath(char **paths, char *cmd)
{
	char	*cmdpath;
	size_t	i;

	if (!access(cmd, X_OK))
	{
		ft_freetab(paths);
		return (cmd);
	}
	i = 0;
	while (paths[i])
	{
		cmdpath = ft_strjoin(paths[i++], cmd);
		if (!access(cmdpath, X_OK))
		{
			ft_freetab(paths);
			return (cmdpath);
		}
		free(cmdpath);
	}
	ft_freetab(paths);
	return (NULL);
}

char	**ft_getpaths(char **env)
{
	char	**env_paths;
	char	*line;
	size_t	i;

	i = 0;
	line = NULL;
	while (env[i] && !line)
		line = ft_strstr(env[i++], "PATH=");
	if (!line)
		return (NULL);
	env_paths = ft_split((line + 5), ':');
	if (!env_paths)
		return (NULL);
	i = 0;
	while (env_paths[i])
	{
		line = ft_strjoin(env_paths[i], "/");
		free(env_paths[i]);
		env_paths[i++] = line;
	}
	return (env_paths);
}
