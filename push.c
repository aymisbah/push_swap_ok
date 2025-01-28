/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymisbah <aymisbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:17:12 by aymisbah          #+#    #+#             */
/*   Updated: 2025/01/28 16:17:14 by aymisbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a2b(t_stack	**a, t_stack	**b)
{
	t_stack	*tmp;

	tmp = (*a);
	(*a) = (*a)->next;
	ft_lstadd_front(b, tmp);
	write(1, "pb\n", 3);
}

void	push_b2a(t_stack	**a, t_stack	**b)
{
	t_stack	*tmp;

	if (!(*b))
		return ;
	tmp = (*b);
	(*b) = (*b)->next;
	ft_lstadd_front(a, tmp);
	write(1, "pa\n", 3);
}

void	push_a(t_stack	**a, t_stack	**b, int flag)
{
	t_stack	*tmp;

	if (!(*b))
		return ;
	tmp = (*b);
	(*b) = (*b)->next;
	ft_lstadd_front(a, tmp);
	write(1, "pa\n", 3);
	if (flag == 1)
		swap(a);
}

void	rotate_both(t_stack	**a, t_stack	**b)
{
	if (!*b || !(*b)->next)
		return ;
	if (!*a || !(*a)->next)
		return ;
	if (*a && (*a)->next)
		rotate(a);
	if (*b && (*b)->next)
		rotate_b(b);
	write(1, "rr\n", 3);
}

void	rrr(t_stack	**a, t_stack	**b)
{
	if ((!*a || !(*a)->next) && (!*b || !(*b)->next))
		return ;
	if (*a && (*a)->next)
		r_rotate(a);
	if (*b && (*b)->next)
		r_rotate(b);
	write(1, "rrr\n", 4);
}
