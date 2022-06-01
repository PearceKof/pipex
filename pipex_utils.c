/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:09:45 by blaurent          #+#    #+#             */
/*   Updated: 2022/05/26 16:55:37 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strstr(const char *str, const char *chr)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (chr[0] == '\0')
		return ((char *)str);
	while (str[i] != '\0')
	{
		if (str[i] == chr[j])
		{
			while (str[i + j] == chr[j])
			{
				j++;
				if (chr[j] == '\0')
					return ((char *)str + i);
			}
			j = 0;
		}
		i++;
	}
	return (NULL);
}
