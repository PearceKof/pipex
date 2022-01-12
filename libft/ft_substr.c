/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 16:27:27 by blaurent          #+#    #+#             */
/*   Updated: 2022/01/07 16:27:27 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = malloc(len);
	if (str == NULL)
		return (NULL);
	i = start - 1;
	while (s[i] != '\0' && len > 0)
	{
		str[j] = s[i];
		i++;
		j++;
		len--;
	}
	str[j] = '\0';
	return (str);
}

// int main()
// {
// 	printf("%s", ft_substr("bonjour", 5, 20));
// }