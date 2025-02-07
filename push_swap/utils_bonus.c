
#include "push_swap_bonus.h"

void err(char **s)
{
	write(2,"Error\n",6);
	free_tab(s);
	exit(1);
}

int	ft_atoi_b(char *str,char **s)
{
	long	res;
	int		i;
	int		sign;

	sign = 1;
	res = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		res = res * 10 + (str[i] - '0');
		i++;
		if (res * sign < INT_MIN || res * sign  > INT_MAX)
			err(s);
	}
	return (res * sign);
}
int	ft_atoi(char *str)
{
	long	res;
	int		i;
	int		sign;

	sign = 1;
	res = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		res = res * 10 + (str[i] - '0');
		i++;
		// if (res * sign < INT_MIN || res * sign  > INT_MAX)
		// 	err(s);
	}
	return (res * sign);
}

void	set_positions(t_stack *head)
{
	t_stack	*current;
	int		pos;

	current = head;
	pos = 0;
	while (current)
	{
		current->pos = pos;
		current = current->next;
		pos++;
	}
}

int	ft_isdigit(int c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}