/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymisbah <aymisbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:42:33 by aymisbah          #+#    #+#             */
/*   Updated: 2025/02/06 18:47:18 by aymisbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	i = 0;
	if (start >= len_s)
		return (NULL);
	if (len > len_s - start)
		len = len_s - start;
	s2 = (char *)malloc(len + 1);
	if (!s2)
		return (NULL);
	while (i < len)
	{
		s2[i] = s[start];
		i++;
		start++;
	}
	s2[i] = '\0';
	return (s2);
}
char	*ft_strjoin(char *s1, char *s2)
{
	size_t		i;
	size_t		j;
	char		*str;

	if (!s1 && !s2)
		return (NULL);
	else if (s1 && !s2)
		return (ft_strdup(s1));
	else if (!s1 && s2)
		return (ft_strdup(s2));
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	j = 0;
	i = 0;
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = 0;
	free(s1);
	s1 = NULL;
	return (str);
}

char	*copy_s(char *s, char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		s[i] = str[i];
		i++;
	}
	i++;
	s[i - 1] = '\n';
	s[i] = '\0';
	return (s);
}
