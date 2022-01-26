/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:31:21 by blaurent          #+#    #+#             */
/*   Updated: 2022/01/05 14:31:21 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n > 0)
	{
		n--;
		p[n] = (unsigned char)c;
	}
	return (s);
}

// int main()
// {
// 	char str[11] = "0123456789";
// 	printf("Avant: %s\n\n", str);
// 	ft_memset(str + 1, 'a', 9);
// 	printf("Apres: %s\n\n", str);
// }