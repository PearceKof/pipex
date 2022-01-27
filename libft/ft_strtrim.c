/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:51:31 by blaurent          #+#    #+#             */
/*   Updated: 2022/01/08 15:51:31 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkc(const char c, const char *set)
{
	unsigned int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	int				start;
	int				end;
	char			*str;

	i = 0;
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_checkc(s1[start], set))
		start++;
	while (ft_checkc(s1[end], set))
		end--;
	if (start >= end)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (end - ft_strlen(s1 + start) + 1));
	if (str == NULL)
		return (NULL);
	while (start <= end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
