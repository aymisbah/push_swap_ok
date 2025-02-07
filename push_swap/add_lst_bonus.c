#include "push_swap_bonus.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!lst)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last -> next = new;
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	new->next = (*lst);
	(*lst) = new;
}

t_stack	*get_middle(t_stack *tmp)
{
	while (tmp && tmp->next && tmp->next->next)
		tmp = tmp->next;
	return (tmp);
}