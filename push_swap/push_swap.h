/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymisbah <aymisbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:48:03 by aymisbah          #+#    #+#             */
/*   Updated: 2025/02/07 16:40:57 by aymisbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				pos;
	int				index;
	struct s_stack	*next;
}	t_stack;

void	check_three(t_stack **a);
void	swap_tw(t_stack *a, t_stack *b);
void	swap(t_stack **head);
void	rotate(t_stack **head);
void	rotate_b(t_stack **head);
void	r_rotate(t_stack **head);
void	r_rotate_b(t_stack **head);
void	rotate_both(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	push_a2b(t_stack **a, t_stack **b);
void	push_b2a(t_stack **a, t_stack **b);
void	push_a(t_stack **a, t_stack **b, int flag);
void	rotate_to_top(t_stack **head, t_stack *node);
void	sort_b(t_stack **head_a, t_stack **head_b, int chunk, int step);

void	swap_tw(t_stack *a, t_stack *b);
void	check_five(t_stack **a, t_stack **b, int flag);
void	check_three(t_stack **a);
void	sort(t_stack **a, t_stack **b);
void	index_nodes(t_stack **head_a);
int		is_in_first_half(t_stack	*head, int target_index);

t_stack	*max_node(t_stack *head);
t_stack	*second_max_node(t_stack *head);
t_stack	*third_max_node(t_stack *head);
t_stack	*min_node(t_stack *head);
t_stack	*get_middle(t_stack *tmp);

void	set_positions(t_stack *head);
int		is_sorted(t_stack *a);
int		set_node_pos(t_stack *head, t_stack *node);

void	which_chunk(t_stack **head_a, int *chunk, int *step);
int		check_chunk(t_stack **head_a, int chunk);
void	calc_actions(t_stack	**head_b, int *actions_max1, int *actions_max2);
void	push_second(t_stack **head_a, t_stack **head_b,
			t_stack *max1, t_stack *max2);

int		ft_valid(char *str);
int		check_doubles(char **str);
int		full_space(char *str);
void	ft_free_arr(char **s);

t_stack	*ft_lstnew(int content);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstclear(t_stack **stack);

int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
int		ft_atoi(char *str);
int		ft_atoi_b(char *str,char **s);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char	*s1, char	*s2);

#endif