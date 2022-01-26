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

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90)
		|| (c >= 97 && c <= 122))
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