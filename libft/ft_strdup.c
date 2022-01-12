/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:48:44 by blaurent          #+#    #+#             */
/*   Updated: 2022/01/12 15:48:44 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strdup(const char *src)
{
	char	*mem;
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	mem = malloc(i * sizeof(char *));
	i = 0;
	while (src[i] != '\0')
	{
		mem[i] = src[i];
		i++;
	}
	return (mem);
}
