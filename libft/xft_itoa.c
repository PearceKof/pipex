/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:10:12 by blaurent          #+#    #+#             */
/*   Updated: 2022/01/08 16:10:12 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdio.h>

static void	*ft_abs(int *n, int *i)
{
	if (*n < 0)
	{
		*n *= -1;
		*i += 1;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	int		i;

	i = 0;
	nbr = n;
	ft_abs(&n, &i);
	while (nbr != 0)
	{
		nbr /= 10;
		i++;
	}
	str = malloc(i * sizeof(char *));
	if (str == NULL)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	str[i] = '\0';
	while (n != 0)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
	}
	str[i] = '\0';
	return (str);
}

int	main(void)
{
	printf("%s\n", ft_itoa(-65));
}
