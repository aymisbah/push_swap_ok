/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_six.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymisbah <aymisbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:16:27 by aymisbah          #+#    #+#             */
/*   Updated: 2025/01/28 16:16:31 by aymisbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_positions(t_stack *head)
{
	t_stack	*current;
	int		pos;

	current = head;
	pos = 0;
	while (current)
	{
		current->pos = pos;
		current = current->next;
		pos++;
	}
}

void	check_three(t_stack	**a)
{
	t_stack	*max;
	t_stack	*min;

	if (!a || !(*a))
		return ;
	max = max_node(*a);
	min = min_node(*a);
	if (max == *a && (*a)->next != min)
	{
		swap(a);
		r_rotate(a);
	}
	if (max == (*a)->next && min == (*a))
	{
		swap(a);
		rotate(a);
	}
	if (*a != min && (*a)->next == max)
		r_rotate(a);
	if (max == (*a) && min == (*a)->next)
		rotate(a);
	else if ((*a)->value > (*a)->next->value)
		swap(a);
}

void	check_five(t_stack	**a, t_stack	**b, int flag)
{
	t_stack	*min;
	int		i;
	int		min_pos;

	if (flag == 0)
		i = 1;
	if (flag == 1)
		i = 0;
	while (i < 2)
	{
		min = min_node(*a);
		min_pos = min->pos;
		while (*a != min)
		{
			if (min_pos > (ft_lstsize(*a) / 2))
				r_rotate(a);
			else
				rotate(a);
		}
		push_a2b(a, b);
		i++;
	}
	check_three(a);
}

void	swap_tw(t_stack *a, t_stack *b)
{
	if (is_sorted(a) == 1)
	{
		if (ft_lstsize(a) == 2)
			swap(&a);
		else if (ft_lstsize(a) == 3)
			check_three(&a);
		else if (ft_lstsize(a) == 4 || ft_lstsize(a) == 5)
		{
			if (ft_lstsize(a) == 4)
				check_five(&a, &b, 0);
			if (ft_lstsize(a) == 5)
			{
				check_five(&a, &b, 1);
				push_b2a(&a, &b);
			}
			push_b2a(&a, &b);
		}
		else if (ft_lstsize(a) >= 6)
			sort(&a, &b);
	}
	ft_lstclear(&a);
}
