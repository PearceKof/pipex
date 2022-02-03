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

static int	ft_countc(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static void	*ft_mallocerror(char **tab, int i)
{
	while (--i >= 0)
		free(tab[i]);
	free(tab);
	return (NULL);
}

static const char	*ft_filltab(char **tab, const char *s, char c)
{
	int	i;
	int	i2;

	i = 0;
	while (*s && *s == c)
		s++;
	while (s[i] && s[i] != c)
		i++;
	*tab = (char *)malloc(sizeof(char) * (i + 1));
	if (!tab)
		return (NULL);
	i2 = -1;
	while (++i2 < i)
		(*tab)[i2] = s[i2];
	(*tab)[i2] = '\0';
	return (&s[i2]);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		nbrofc;
	char	**tab;

	if (!s)
		return (NULL);
	i = 0;
	nbrofc = ft_countc(s, c);
	tab = (char **)malloc(sizeof(char *) * (nbrofc + 1));
	if (!tab)
		return (NULL);
	i = -1;
	while (++i < nbrofc)
	{
		s = ft_filltab(&tab[i], s, c);
		if (!tab[i])
			return (ft_mallocerror(tab, i));
	}
	tab[i] = NULL;
	return (tab);
}
