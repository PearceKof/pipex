/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:47:29 by blaurent          #+#    #+#             */
/*   Updated: 2022/01/12 15:47:29 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t size)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned int	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	while (size > 0)
	{
		d[i] = s[i];
		size--;
		i++;
	}
	return (dst);
}

// int main()
// {
// 	char str1[11] = "0123456789";
// 	char str2[11] = "9876543210";
// 	printf("%s\n", str2);
// 	ft_memcpy(str2, str1, 11*sizeof(char));
// 	printf("%s", str2);
// }