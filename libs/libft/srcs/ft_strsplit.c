/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 14:41:39 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/21 14:34:53 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_cnt_words(char const *s, char c)
{
	int		i;
	int		total;

	i = 0;
	total = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			total++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (total);
}

static	size_t	len_word(char const *s, char c)
{
	size_t total;

	if (!s)
		return (0);
	total = 0;
	while (s[total] && s[total] != c)
		total++;
	return (total);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;

	if (!s || !(tab = (char **)malloc(sizeof(char *) *
					(ft_cnt_words(s, c) + 1))))
		return (NULL);
	j = 0;
	i = 0;
	while (j < ft_cnt_words(s, c))
	{
		while (s[i] == c)
			i++;
		if (!(tab[j] = ft_strnew(len_word(s + i, c))))
			return (NULL);
		ft_strncpy(tab[j], s + i, len_word(s + i, c));
		i += len_word(s + i, c);
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
