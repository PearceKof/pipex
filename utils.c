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

void	ft_error(char *where, char **freed,  int ret)
{
	perror(where);
	if (freed)
		ft_freetab(freed);
	exit(ret);
}

void	exec(char *av, char **env, int ret)
{
	char	**env_paths;
	char	**option;
	char	*cmdpath;

	env_paths = ft_getpaths(env);
	if (!env_paths)
		ft_error("env", NULL, ret);
	option = ft_split(av, ' ');
	if (!option)
		ft_error("ft_split", env_paths,  ret);
	cmdpath = ft_cmdpath(env_paths, option[0]);
	if (!cmdpath)
	{
		ft_freetab(option);
		ft_fprintf(STDERR_FILENO, "%s : command not found\n", av);
		exit(127);
	}
	if (execve(cmdpath, option, env) == -1)
	{
		free(cmdpath);
		ft_error("execve failed", option, 126);
	}
}

char	*ft_cmdpath(char **paths, char *cmd)
{
	char	*cmdpath;
	size_t	i;

	if (!access(cmd, F_OK))
	{
		cmdpath = ft_strjoin("", cmd);
		ft_freetab(paths);
		return (cmd);
	}
	i = 0;
	while (paths[i])
	{
		cmdpath = ft_strjoin(paths[i++], cmd);
		if (!cmdpath || !access(cmdpath, F_OK))
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
