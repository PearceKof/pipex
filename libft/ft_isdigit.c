/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:20:34 by blaurent          #+#    #+#             */
/*   Updated: 2022/01/04 12:20:34 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	isalpha(int argument)
{
	if (argument >= 48 && argument <= 57)
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
// 	if (isalpha('a'))
// 	{
// 		printf("est numerique");
// 	}
// 	else
// 	{
// 		printf("n'est pas numerique");
// 	}
// }