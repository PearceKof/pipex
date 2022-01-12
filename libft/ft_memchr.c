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
	char	*ptr;

	ptr = (char *)str;
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
// 	char test[11] = "Salut bg :D";
// 	printf("Avant: %s", test);
// 	printf("Apres: %s", ft_memchr(test, 'b', 20));
// }