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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * ft_strlen(s + start) + 1);
	if (str == NULL)
		return (NULL);
	i = start;
	while (s[i] && len > 0 && start <= ft_strlen(s))
	{
		str[j] = s[i];
		i++;
		j++;
		len--;
	}
	str[j] = '\0';
	return (str);
}

// #include <stdio.h>
// int main()
// {
// 	printf("%s", ft_substr("BONJOUR LES HARICOTS !", 8, 15));
// }