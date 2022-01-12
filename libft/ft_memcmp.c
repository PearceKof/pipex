/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:47:07 by blaurent          #+#    #+#             */
/*   Updated: 2022/01/12 15:47:07 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	memcmp( const void *pointer1, const void *pointer2, size_t size )
{
	int	i;
	int	returned;

	i = 0;
	returned = 0;
	while (i <= size)
	{
		if (pointer1 != pointer2)
		i++;
	}
	return (returned);
}
