#include "push_swap_bonus.h"

void	error(char	**str)
{
	int	i;

	i = 0;
	write(2, "Error\n", 6);
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	**ft_check(char	**av)
{
	int		i;
	char	*str;
	char	**split;

	i = 1;
	str = NULL;
	while (av[i])
	{
		if (full_space(av[i]) == 0)
			return (NULL);
		str = ft_strjoin(str, av[i]);
		str = ft_strjoin(str, " ");
		i++;
	}
	split = ft_split(str, ' ');
	free(str);
	i = 0;
	while (split[i])
	{
		if (ft_valid(split[i]) == 0 || check_doubles(split) == 0)
			return (error(split), NULL);
		i++;
	}
	return (split);
}

void free_tab(char **str)
{
	int i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free (str);
}
void	create_stack(char	**str, t_stack	**a)
{
	int	i;
	int	n;

	i = 0;
	while (str[i])
	{
		n = ft_atoi_b(str[i],str);
		if (!a)
			*a = ft_lstnew(n);
		else
			ft_lstadd_back(a, ft_lstnew(n));
		i++;
	}
	set_positions(*a);
}

int	is_sorted(t_stack	*a)
{
	while (a->next)
	{
		if (a->value > a->next->value)
			return (1);
		a = a->next;
	}
	return (0);
}

void do_actions(t_stack **a,t_stack **b,char *str)
{
	if (!strcmp(str,"sa\n"))
		swap(a);
	else if (!strcmp(str,"ra\n") )
		rotate(a);
	else if (!strcmp(str,"rb\n"))
		rotate_b(b);
	else if (!strcmp(str,"rra\n"))
		r_rotate(a);
	else if (!strcmp(str,"rrb\n"))
		r_rotate_b(b);
	else if (!strcmp(str,"pa\n"))
		push_b2a(a, b);
	else if (!strcmp(str,"pb\n"))
		push_a2b(a, b);
	else if (!strcmp(str,"rr\n"))
		rotate_both(a, b);
	else if (!strcmp(str,"rrr\n"))
		rrr(a, b);
	// else
	// {
	// 	write(2,"Error\n",6);
	// }
}

int check_valid(char *str)
{
	if (!strcmp(str,"sa\n"))
		return(1);
	else if (!strcmp(str,"ra\n") )
		return(1);
	else if (!strcmp(str,"rb\n"))
		return(1);
	else if (!strcmp(str,"rra\n"))
		return(1);
	else if (!strcmp(str,"rrb\n"))
		return(1);
	else if (!strcmp(str,"pa\n"))
		return(1);
	else if (!strcmp(str,"pb\n"))
		return(1);
	else if (!strcmp(str,"rr\n"))
		return(1);
	else if (!strcmp(str,"rrr\n"))
		return(1);
	else
		return (0);
}
void check_s(t_stack **a,t_stack **b,int flag)
{
	if (flag == 0)
	{
		if(is_sorted(*a) == 0)
			write(1,"OK\n",3);
		else
			write(1,"KO\n",3);
	}
	if (flag == 1)
	{
		if(is_sorted(*a) == 0 && !(*b))
			write(1,"OK\n",3);
		else
			write(1,"KO\n",3);
	}
}
char **read_input(t_stack **a,t_stack **b)
{
    char *line;
	char *str;
	char **tab;

    line = get_next_line(0);
	str = NULL;
	if (!line )
		check_s(a,b,0);
    while (line)
	{
		if (check_valid(line) == 0)
		{
			write(2,"Error\n",6);
			ft_lstclear(a);
			free(line);
			free(str);
			exit(-1);
		}
		str = ft_strjoin(str,line);
		str = ft_strjoin(str," ");
		free(line);
		line = get_next_line(0);
	}
	tab = ft_split(str,' ');
	return (free(str),tab);
}


int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**str;
	char	**tab;
	int i;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	else
		str = ft_check(av);
	if (!str)
		return (0);
	create_stack(str, &a);
	free_tab(str);
    tab = read_input(&a,&b);
	if (!tab)
		return(ft_lstclear(&a),0);
	i = 0;
	while(tab[i])
	{
		do_actions(&a,&b,tab[i]);
		i++;
	}
	check_s(&a,&b,1);
	return(free_tab(tab),ft_lstclear(&a),ft_lstclear(&b),0);
}
