/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymisbah <aymisbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:17:58 by aymisbah          #+#    #+#             */
/*   Updated: 2025/01/28 16:20:24 by aymisbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(const char *s1)
{
	char		*str;
	size_t		i;
	size_t		len_s;

	i = 0;
	len_s = ft_strlen(s1);
	str = (char *)malloc ((len_s + 1));
	if (!str)
		return (NULL);
	while (i < len_s)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
