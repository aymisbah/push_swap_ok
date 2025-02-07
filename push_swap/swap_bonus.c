/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymisbah <aymisbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:04:09 by aymisbah          #+#    #+#             */
/*   Updated: 2025/02/06 18:07:38 by aymisbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(t_stack	**head)
{
	t_stack	*tmp;

	if (!*head || !(*head)->next)
		return ;
	tmp = (*head)->next;
	(*head)->next = tmp->next;
	tmp->next = (*head);
	(*head) = tmp;
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
}
