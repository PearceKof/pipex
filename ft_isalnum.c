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

int	ft_isalnum(int c)
{
	if (((c >= 65 && c <= 90)
			|| (c >= 97 && c <= 122))
		|| (c >= 48 && c <= 57))
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
// 	if (ft_isalpha(')'))
// 	{
// 		printf("est alphanumerique");
// 	}
// 	else
// 	{
// 		printf("n'est pas alphanumerique");
// 	}
// }