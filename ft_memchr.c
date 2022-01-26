/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:46:37 by blaurent          #+#    #+#             */
/*   Updated: 2022/01/12 15:46:37 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	while (n > 0)
	{
		if (*ptr == c)
		{
			return (ptr);
		}
		ptr++;
		n--;
	}
	return (NULL);
}

// int main()
// {
// 	char test[] = "têst";
// 	printf("%s\n", ft_memchr(test, 234, 2));
// 	printf("%s", memchr(test, 234, 2));
// }