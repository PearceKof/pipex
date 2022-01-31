/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:05:14 by blaurent          #+#    #+#             */
/*   Updated: 2022/01/08 16:05:14 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_mallocerror(char **tab)
{
	unsigned int	i;

	i = 0;
	while (!tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static int	ft_count(char const *s, char c)
{
	unsigned int	i;
	int				cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			cnt++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (cnt);
}

static char	*ft_strndup(const char *s, size_t n, char **tab)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(sizeof(char) * n + 1);
	if (!str)
		return (ft_mallocerror(tab));
	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	unsigned int		i;
	unsigned int		j;
	unsigned int		k;
	char				**tab;

	i = 0;
	k = 0;
	tab = (char **)malloc(sizeof(char *) * (ft_count(s, c)) + 1);
	if (!tab || !s)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		if (i > j)
		{
			tab[k] = ft_strndup(s + j, i - j, tab);
			k++;
		}
	}
	tab[k] = NULL;
	return (tab);
}
