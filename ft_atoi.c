/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:00:52 by blaurent          #+#    #+#             */
/*   Updated: 2022/01/19 16:00:52 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned int	i;
	unsigned int	value;
	int				neg;

	neg = 1;
	i = 0;
	value = 0;
	if (str[0] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[0] == '+')
	{
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		value *= 10;
		value += str[i] - '0';
		i++;
	}
	return (value * neg);
}

// int	main(void)
// {
// 	printf("%d\n", atoi("-1"));
// 	printf("%d", ft_atoi("-1"));
// }