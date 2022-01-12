/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:38:08 by blaurent          #+#    #+#             */
/*   Updated: 2022/01/07 12:38:08 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
		{
			return (s1[i] - s2[i]);
		}
		n--;
		i++;
	}
	return (0);
}

// int main () {
// 	char str1[20];
// 	char str2[20];
// 	int result;

// 	strcpy(str1, "hello");
// 	strcpy(str2, "helLO WORLD");

// 	//This will compare the first 4 characters
// 	result = ft_strncmp(str1, str2, 4);

// 	if(result > 0) {
//printf("str1 is greater than str2");
// 	} else if(result < 0) {
//printf("str1 is less than str2");
// 	} else {
// 		printf("Both the strings str1 and str2 are equal");
// 	}

// 	return 0;
// }