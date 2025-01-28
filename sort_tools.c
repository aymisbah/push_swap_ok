/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymisbah <aymisbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:17:29 by aymisbah          #+#    #+#             */
/*   Updated: 2025/01/28 20:55:00 by aymisbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_node_pos(t_stack	*head, t_stack	*node)
{
	int	pos;

	pos = 0;
	while (head && head != node)
	{
		head = head->next;
		pos++;
	}
	return (pos);
}

void	rotate_to_top(t_stack **head, t_stack *node)
{
	int	pos;
	int	size;

	pos = set_node_pos(*head, node);
	size = ft_lstsize(*head);
	if (pos <= size / 2)
	{
		while (*head != node)
			rotate_b(head);
	}
	else
	{
		while (*head != node)
			r_rotate_b(head);
	}
}

void	index_nodes(t_stack	**head_a)
{
	t_stack	*curr;
	t_stack	*min_node;
	int		index;
	int		total_nodes;

	total_nodes = ft_lstsize(*head_a);
	index = 0;
	while (index < total_nodes)
	{
		curr = *head_a;
		min_node = NULL;
		while (curr)
		{
			if ((min_node == NULL || curr->value < min_node->value)
				&& curr->index == -1)
				min_node = curr;
			curr = curr->next;
		}
		if (min_node)
			min_node->index = index++;
	}
	set_positions(*head_a);
}

int	is_in_first_half(t_stack	*head, int target_index)
{
	t_stack	*curr;
	int		size;
	int		pos;

	curr = head;
	size = ft_lstsize(head);
	pos = 0;
	while (curr)
	{
		if (curr->index == target_index)
			return (pos < (size / 2));
		curr = curr->next;
		pos++;
	}
	return (0);
}

void	sort_b(t_stack **head_a, t_stack **head_b, int chunk, int step)
{
	push_a2b(head_a, head_b);
	if ((*head_b)->index >= (chunk - (step / 2)))
		rotate_b(head_b);
}
