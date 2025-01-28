/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymisbah <aymisbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:16:46 by aymisbah          #+#    #+#             */
/*   Updated: 2025/01/28 16:18:52 by aymisbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(char	**str)
{
	int	i;

	i = 0;
	write(2, "Error\n", 6);
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	**ft_check(char	**av)
{
	int		i;
	char	*str;
	char	**split;

	i = 1;
	str = NULL;
	while (av[i])
	{
		if (full_space(av[i]) == 0)
			return (NULL);
		str = ft_strjoin(str, av[i]);
		str = ft_strjoin(str, " ");
		i++;
	}
	split = ft_split(str, ' ');
	free(str);
	i = 0;
	while (split[i])
	{
		if (ft_valid(split[i]) == 0 || check_doubles(split) == 0)
			return (error(split), NULL);
		i++;
	}
	return (split);
}

void	create_stack(char	**str, t_stack	**a)
{
	int	i;
	int	n;

	i = 0;
	while (str[i])
	{
		n = ft_atoi(str[i]);
		if (!a)
			*a = ft_lstnew(n);
		else
			ft_lstadd_back(a, ft_lstnew(n));
		i++;
	}
	set_positions(*a);
}

int	is_sorted(t_stack	*a)
{
	while (a->next)
	{
		if (a->value > a->next->value)
			return (1);
		a = a->next;
	}
	return (0);
}

int	main(int ac, char **av)
{
	char	**str;
	t_stack	*a;
	t_stack	*b;
	int		i;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	else
		str = ft_check(av);
	if (!str)
		return (0);
	create_stack(str, &a);
	swap_tw(a, b);
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free (str);
}
