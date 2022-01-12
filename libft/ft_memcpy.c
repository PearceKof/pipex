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
	char	*ptr1;
	char	*ptr2;
	int		i;

	ptr1 = (char *)dst;
	ptr2 = (char *)src;
	i = 0;
	while (size > 0)
	{
		*(ptr1 + i) = *(ptr2 + i);
		size--;
		i++;
	}
}

// int main()
// {
// 	char str1[11] = "0123456789";
// 	char str2[11] = "9876543210";
// 	printf("%s\n", str2);
// 	ft_memcpy(str2, str1, 11*sizeof(char));
// 	printf("%s", str2);
// }