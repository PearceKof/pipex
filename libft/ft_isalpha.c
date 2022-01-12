/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:20:37 by blaurent          #+#    #+#             */
/*   Updated: 2022/01/04 12:20:37 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	isalpha(int argument)
{
	if ((argument >= 65 && argument <= 90)
		|| (argument >= 97 && argument <= 122))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

// int main(void)
// {
// 	if (isalpha('2'))
// 	{
// 		printf("est alphae");
// 	}
// 	else
// 	{
// 		printf("n'est pas alpha");
// 	}
// }