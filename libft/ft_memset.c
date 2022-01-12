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
	char	*p;

	p = (char *)s;
	while (n > 0)
	{
		p[n - 1] = (char)c;
		n--;
	}
}

// int main()
// {
// 	char str[11] = "0123456789";
// 	printf("Avant: %s\n\n", str);
// 	ft_memset(str , 0, 3);
// 	printf("Apres: %s\n\n", str);
// }