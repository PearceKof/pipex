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

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (dst == NULL && src == NULL)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = len - 1;
	while (len > 0)
	{
		d[i] = s[i];
		i--;
		len--;
	}
	return (dst);
}

// int main(void)
// {
// 	char stra[5] = "01234";
// 	char strb[11] = "abcdefghij";
// 	char sResult[] = "ghghi\0-";
// 	ft_memmove(sResult + 1, sResult, 2);//sResult+1=hghi ghhi
// 	printf("%s\n", sResult);
// 	char sResultbis[] = "ghghi\0-";
// 	memmove(sResultbis + 1, sResultbis, 2);//sResult+1=hghi ghhi
// 	printf("%s\n", sResultbis);
// }