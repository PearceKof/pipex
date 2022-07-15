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

void	ft_error(char *where, char **freed, int ret)
{
	perror(where);
	if (freed)
		ft_freetab(freed);
	exit(ret);
}

void	exec(char *av, char **env)
{
	char	**option;
	char	*cmdpath;

	option = ft_split(av, ' ');
	if (!option)
		ft_error("ft_split", NULL, EXIT_FAILURE);
	cmdpath = ft_getpaths(env, option[0]);
	if (!cmdpath)
	{
		ft_fprintf(STDERR_FILENO, "%s : command not found\n", option[0]);
		ft_freetab(option);
		exit(127);
	}
	if (execve(cmdpath, option, env) == -1)
	{
		free(cmdpath);
		ft_error("execve failed", option, 126);
	}
}

char	*checkpaths(char **env_paths, char *cmd)
{
	char	*cmdpath;
	char	*tmp;
	size_t	i;

	i = 0;
	while (env_paths[i])
	{
		tmp = ft_strjoin(env_paths[i++], "/");
		cmdpath = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!access(cmdpath, X_OK))
		{
			ft_freetab(env_paths);
			return (cmdpath);
		}
		free(cmdpath);
	}
	ft_freetab(env_paths);
	return (NULL);
}

char	*ft_getpaths(char **env, char *cmd)
{
	char	**env_paths;
	char	*ptr;
	size_t	i;

	if (ft_strstr(cmd, "/"))
	{
		if (access(cmd, X_OK))
			ft_error(cmd, NULL, 127);
		ptr = ft_strdup(cmd);
		return (ptr);
	}
	i = 0;
	ptr = NULL;
	while (env[i] && !ptr)
		ptr = ft_strstr(env[i++], "PATH=");
	if (!ptr)
		return (NULL);
	env_paths = ft_split((ptr + 5), ':');
	return (checkpaths(env_paths, cmd));
}
