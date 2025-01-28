/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools_tw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymisbah <aymisbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:17:18 by aymisbah          #+#    #+#             */
/*   Updated: 2025/01/28 16:17:20 by aymisbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_chunk(t_stack **head_a, int chunk)
{
	t_stack	*node;

	node = *head_a;
	while (node)
	{
		if (node->index < chunk)
			return (0);
		node = node->next;
	}
	return (1);
}

void	which_chunk(t_stack **head_a, int *chunk, int *step)
{
	int	size;

	size = ft_lstsize(*head_a);
	if (size <= 200)
	{
		*chunk = size / 5;
		*step = size / 5;
	}
	else
	{
		*chunk = size / 11;
		*step = size / 11;
	}
}

void	calc_actions(t_stack	**head_b, int actions_max1, int actions_max2)
{
	t_stack	*max1;
	t_stack	*max2;
	int		size;
	int		max1_pos;
	int		max2_pos;

	max1 = max_node(*head_b);
	max2 = second_max_node(*head_b);
	max1_pos = set_node_pos(*head_b, max1);
	max2_pos = set_node_pos(*head_b, max2);
	size = ft_lstsize(*head_b);
	if (max1_pos <= size / 2)
		actions_max1 = max1_pos + 1;
	else
		actions_max1 = size - max1_pos;
	if (max2_pos <= size / 2)
		actions_max2 = max2_pos + 1;
	else
		actions_max2 = size - max2_pos + 2;
}

void	push_second(t_stack **head_a, t_stack **head_b
	, t_stack *max1, t_stack *max2)
{
	rotate_to_top(head_b, max2);
	push_b2a(head_a, head_b);
	if (*head_b)
	{
		rotate_to_top(head_b, max1);
		push_b2a(head_a, head_b);
		swap(head_a);
	}
}
