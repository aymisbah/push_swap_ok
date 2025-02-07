/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymisbah <aymisbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:19:54 by aymisbah          #+#    #+#             */
/*   Updated: 2025/02/07 13:52:54 by aymisbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char const *s, char sep)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s && s[i])
	{
		while (s[i] == sep && s[i])
			i++;
		if (s[i] != sep && s[i])
			++count;
		while (s[i] && s[i] != sep)
			i++;
	}
	return (count);
}

static int	word_len(char const *s, char sep)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != sep)
		i++;
	return (i);
}

void	ft_free_arr(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		l;

	if (!s)
		return (NULL);
	l = count_words(s, c);
	i = 0;
	tab = (char **) malloc(sizeof(char *) * (l + 1));
	if (!tab)
		return (NULL);
	while (i < l)
	{
		while (*s == c && *s)
			s++;
		tab[i] = (char *)malloc (word_len(s, c) + 1);
		if (!tab[i])
			return (ft_free_arr(tab), NULL);
		ft_strlcpy(tab[i++], s, word_len(s, c) + 1);
		s += word_len(s, c);
	}
	tab [i] = NULL;
	return (tab);
}
