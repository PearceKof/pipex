/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:20:31 by blaurent          #+#    #+#             */
/*   Updated: 2022/01/04 12:20:31 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	isalpha(int argument)
{
	if (((argument >= 65 && argument <= 90)
			|| (argument >= 97 && argument <= 122))
		|| (argument >= 48 && argument <= 57))
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
// 	if (isalpha(')'))
// 	{
// 		printf("est alphanumerique");
// 	}
// 	else
// 	{
// 		printf("n'est pas alphanumerique");
// 	}
// }