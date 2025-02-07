/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymisbah <aymisbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:17:50 by aymisbah          #+#    #+#             */
/*   Updated: 2025/01/30 16:17:06 by aymisbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack	**head)
{
	t_stack	*tmp;

	if (!*head || !(*head)->next)
		return ;
	tmp = (*head)->next;
	(*head)->next = tmp->next;
	tmp->next = (*head);
	(*head) = tmp;
	write(1, "sa\n", 3);
}

void	rotate(t_stack	**head)
{
	t_stack	*tmp;
	t_stack	*last;

	tmp = (*head);
	(*head) = (*head)->next;
	last = ft_lstlast(*head);
	last->next = tmp;
	tmp->next = NULL;
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack	**head_b)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*head_b || !(*head_b)->next)
		return ;
	tmp = (*head_b);
	(*head_b) = (*head_b)->next;
	last = ft_lstlast(*head_b);
	last->next = tmp;
	tmp->next = NULL;
	write(1, "rb\n", 3);
}

void	r_rotate(t_stack	**head)
{
	t_stack	*last;
	t_stack	*middle;

	middle = get_middle(*head);
	last = middle->next;
	middle->next = NULL;
	last->next = *head;
	*head = last;
	write(1, "rra\n", 4);
}

void	r_rotate_b(t_stack	**head)
{
	t_stack	*last;
	t_stack	*middle;

	if (!*head || !(*head)->next)
		return ;
	middle = get_middle(*head);
	last = middle->next;
	middle->next = NULL;
	last->next = *head;
	*head = last;
	write(1, "rrb\n", 4);
}
