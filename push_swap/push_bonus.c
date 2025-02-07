#include "push_swap_bonus.h"

void	push_a2b(t_stack	**a, t_stack	**b)
{
	t_stack	*tmp;

	tmp = (*a);
	(*a) = (*a)->next;
	ft_lstadd_front(b, tmp);
}

void	push_b2a(t_stack	**a, t_stack	**b)
{
	t_stack	*tmp;

	if (!(*b))
		return ;
	tmp = (*b);
	(*b) = (*b)->next;
	ft_lstadd_front(a, tmp);
}

void	push_a(t_stack	**a, t_stack	**b)
{
	t_stack	*tmp;

	if (!(*b))
		return ;
	tmp = (*b);
	(*b) = (*b)->next;
	ft_lstadd_front(a, tmp);
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
}

void	rrr(t_stack	**a, t_stack	**b)
{
	if ((!*a || !(*a)->next) && (!*b || !(*b)->next))
		return ;
	if (*a && (*a)->next)
		r_rotate(a);
	if (*b && (*b)->next)
		r_rotate_b(b);
}