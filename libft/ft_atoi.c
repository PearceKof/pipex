/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:52:24 by blaurent          #+#    #+#             */
/*   Updated: 2022/01/10 13:52:24 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdio.h>

int	ft_atoi(const char *str)
{
	long	value;
	int		i;
	int		neg;

	neg = 1;
	i = 0;
	value = 0;
	if (str[0] == '-')
	{
		neg = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		value *= 10;
		value += str[i] - '0';
		i++;
	}
	return (value * neg);
}

int	main(void)
{
	printf("%d", ft_atoi("247483647"));
}
