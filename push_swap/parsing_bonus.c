#include "push_swap_bonus.h"

int	full_space(char	*str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' && str[i] != 0)
		i++;
	if (str[i] == '\0')
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	ft_valid(char	*str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_doubles(char	**str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if ((ft_atoi(str[i]) == ft_atoi(str[j])))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}