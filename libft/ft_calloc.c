/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:49:04 by blaurent          #+#    #+#             */
/*   Updated: 2022/01/12 15:49:04 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	char	*p;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	p = (char *)ptr;
	while (count > 0)
	{
		p[count - 1] = 0;
		count--;
	}
	return (ptr);
}
