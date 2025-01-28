/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymisbah <aymisbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:16:55 by aymisbah          #+#    #+#             */
/*   Updated: 2025/01/28 16:19:09 by aymisbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*max_node(t_stack	*head)
{
	t_stack	*max;

	if (!head)
		return (NULL);
	max = head;
	while (head)
	{
		if (head->value > max->value)
			max = head;
		head = head->next;
	}
	return (max);
}

t_stack	*second_max_node(t_stack	*head)
{
	t_stack	*max;
	t_stack	*second_max;

	max = max_node(head);
	second_max = NULL;
	while (head)
	{
		if (head != max && (!second_max || head->index > second_max->index))
			second_max = head;
		head = head->next;
	}
	return (second_max);
}

t_stack	*third_max_node(t_stack	*head)
{
	t_stack	*max;
	t_stack	*second_max;
	t_stack	*third_max;

	max = max_node(head);
	second_max = second_max_node(head);
	third_max = NULL;
	while (head)
	{
		if (head != max && head != second_max
			&& (!third_max || head->value > third_max->value))
		{
			third_max = head;
		}
		head = head->next;
	}
	return (third_max);
}

t_stack	*min_node(t_stack *head)
{
	t_stack	*min;

	if (!head)
		return (NULL);
	min = head;
	while (head)
	{
		if (head->value < min->value)
			min = head;
		head = head->next;
	}
	return (min);
}

t_stack	*get_middle(t_stack *tmp)
{
	while (tmp && tmp->next && tmp->next->next)
		tmp = tmp->next;
	return (tmp);
}
