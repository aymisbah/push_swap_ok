
#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H


# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_stack
{
	int				value;
	int				pos;
	int				index;
	struct s_stack	*next;
}	t_stack;

// void	swap_bonus(t_stack	**head);
char	*get_next_line(int fd);

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
void	push_a(t_stack **a, t_stack **b);
void	rotate_to_top(t_stack **head, t_stack *node);
void	sort_b(t_stack **head_a, t_stack **head_b, int chunk, int step);
t_stack	*get_middle(t_stack *tmp);





void	set_positions(t_stack *head);





int		ft_valid(char *str);
int	check_doubles(char	**str);
int		full_space(char *str);

t_stack	*ft_lstnew(int content);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstclear(t_stack **stack);
void free_tab(char **str);

int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
int		ft_atoi(char *str);
char	**ft_split(char const *s, char c);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char	*s1, char	*s2);
int	ft_atoi_b(char *str,char **s);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*copy_s(char *s, char *str);

#endif