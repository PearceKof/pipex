/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:19:22 by blaurent          #+#    #+#             */
/*   Updated: 2022/01/11 18:19:22 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (size == 0)
		return (len);
	while (src[i] != '\0' && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

// int main()
// {
// 	char s1[30] = "0123456789";
// 	char s2[11] = "abcdefghij";
// 	char sa[30] = "0123456789";
// 	char sb[11] = "abcdefghij";
// 	printf("%ld, %s, %s\n", ft_strlcpy(s1, s2, 9), s1, s2);
// 	// printf("%ld, %s, %s\n", strlcpy(sa, sb, 9), sa, sb);
// }