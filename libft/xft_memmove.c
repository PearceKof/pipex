/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xft_memmove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:50:02 by blaurent          #+#    #+#             */
/*   Updated: 2022/01/12 16:34:35 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include <string.h>
#include <stdio.h>

void *ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	i = 0;
	while (len > 0)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
		len--;
	}
	return (dst);
}

int main(void)
{
	char stra[11] = "012346789";
	char strb[11] = "abcdefghij";
	ft_memmove(stra, strb, 5);
	printf("%s\n%s\n", stra, strb);
}
