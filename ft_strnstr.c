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

#include "libft.h"

char	*ft_strnstr(const char *str, const char *chr, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (str[0] == '\0' && chr[0] == '\0')
		return ((char *)str);
	while (str[i] != '\0' && n > 0)
	{
		if (str[i] == chr[j])
		{
			while (str[i + j] == chr[j] && (n - j) > 0)
			{
				j++;
				if (chr[j] == '\0')
					return ((char *)str + i);
			}
			j = 0;
		}
		i++;
		n--;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// int main(void) {
// 	char haystack[30] = "aaabcabcd";
// 	char needle[10] = "aabc";
// 	char * empty = (char*)"";
// 	printf("found: %s\n", ft_strnstr(haystack, "cd", 8));
// 	printf("found: %s\n", strnstr(haystack, "cd", 8));
// 	return 0;
// }