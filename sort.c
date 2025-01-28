/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymisbah <aymisbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:17:39 by aymisbah          #+#    #+#             */
/*   Updated: 2025/01/28 20:52:23 by aymisbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_target(t_stack	*head_a, int chunk)
{
	t_stack	*curr;

	curr = head_a;
	while (curr)
	{
		if (curr->index < chunk)
			return (curr->index);
		curr = curr->next;
	}
	return (-1);
}

void	check_index(t_stack	**head_a, int chunk)
{
	int	target;
	int	i;

	target = find_target(*head_a, chunk);
	i = 0;
	while (i < 1)
	{
		if (is_in_first_half(*head_a, target))
			rotate(head_a);
		else
			r_rotate(head_a);
		i++;
	}
}

void	push_to_b(t_stack	**head_a, t_stack	**head_b, int chunk, int step)
{
	t_stack	*max1;
	t_stack	*max2;
	t_stack	*max3;

	max1 = max_node(*head_a);
	max2 = second_max_node(*head_a);
	max3 = third_max_node(*head_a);
	while (*head_a)
	{
		if (*head_a == max1 || *head_a == max2 || *head_a == max3)
		{
			if (ft_lstsize(*head_a) > 3)
				rotate(head_a);
			else
				break ;
		}
		else if ((*head_a)->index < chunk)
			sort_b(head_a, head_b, chunk, step);
		else
			rotate(head_a);
		if (check_chunk(head_a, chunk))
			chunk += step;
	}
}

void	push_to_a(t_stack	**head_a, t_stack	**head_b)
{
	t_stack	*max1;
	t_stack	*max2;
	int		actions_max1;
	int		actions_max2;

	while (*head_b)
	{
		max1 = max_node(*head_b);
		max2 = second_max_node(*head_b);
		actions_max1 = 0;
		actions_max2 = 0;
		calc_actions(head_b, actions_max1, actions_max2);
		if (actions_max1 <= actions_max2)
		{
			rotate_to_top(head_b, max1);
			push_b2a(head_a, head_b);
		}
		else
			push_second(head_a, head_b, max1, max2);
	}
}

void	sort(t_stack	**a, t_stack	**b)
{
	int	chunk;
	int	step;

	index_nodes(a);
	which_chunk(a, &chunk, &step);
	push_to_b(a, b, chunk, step);
	check_three(a);
	push_to_a(a, b);
}
