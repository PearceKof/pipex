/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:55:24 by blaurent          #+#    #+#             */
/*   Updated: 2022/01/07 12:55:24 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*returned;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] != '\0' && n > 0)
	{
		if (s1[i] == s2[j])
		{
			while (s1[i + j] == s2[j] && (n - j) > 0)
			{
				j++;
				if (s2[j] == '\0')
				{
					returned = s1 + i;
					return (returned);
				}
			}
			j = 0;
		}
		i++;
		n--;
	}
	return (NULL);
}

// int main(void) {
// 	printf("found: %s\n", ft_strnstr("abcdef", "ef", 6));
// 	printf("found: %s\n", ft_strnstr("in", "searchingFor", 20));
// 	printf("found: %s\n", ft_strnstr("in", "searchingFor", 20));
// 	return 0;
// }