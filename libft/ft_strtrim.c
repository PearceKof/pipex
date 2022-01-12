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
#include<stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != *set)
			j++;
		i++;
	}
	str = malloc(j * sizeof(char *));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != *set)
			str[j++] = s1[i];
		i++;
	}
	str[j] = '\0';
	return (str);
}

// int main()
// {
// 	printf("%s\n", ft_strtrim("Bonjour", "r"));
// }