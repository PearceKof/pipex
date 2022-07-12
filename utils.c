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

void	ft_perror(char *err, int ret)
{
	perror(err);
	exit(ret);
}

void	ft_error(char *mess, char *where, int ret)
{
	if (where)
		ft_fprintf(STDERR_FILENO, "%s: %s\n", mess, where);
	else if (mess)
		perror(mess);
	exit(ret);
}

void	exec(char *av, char **env, int status)
{
	char	**env_paths;
	char	**option;
	char	*cmdpath;

	env_paths = ft_getpaths(env);
	option = ft_split(av, ' ');
	cmdpath = ft_cmdpath(env_paths, option[0]);
	if (!cmdpath)
		ft_error("command not found", av, 127);
	if (execve(cmdpath, option, env) == -1)
	{
		ft_freetab(option);
		free(cmdpath);
		ft_perror("execve failed", 126);
	}
	ft_freetab(option);
	free(cmdpath);
	exit(status);
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
	free(cmd);
	return(NULL);
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
	i = 0;
	while (env_paths[i])
	{
		line = ft_strjoin(env_paths[i], "/");
		free(env_paths[i]);
		env_paths[i++] = line;
	}
	return (env_paths);
}
