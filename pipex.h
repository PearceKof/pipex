/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:53:06 by blaurent          #+#    #+#             */
/*   Updated: 2022/06/03 12:41:10 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "mylib/includes/libft.h"
# include "mylib/includes/ft_printf.h"
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>

int		ft_fcmd(char **av, char **paths,  char **env, int *fd);
int		ft_scmd(char **av, char **paths,  char **env, int *fd);
char	*ft_cmdpath(char **paths, char *cmd);
char	**ft_getpaths(char **envp);
void 	exec(char *av, char **env);
void	ft_error(char *mess, char *error);

#endif
