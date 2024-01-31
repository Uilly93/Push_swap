/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_and_errors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:57:12 by wnocchi           #+#    #+#             */
/*   Updated: 2024/01/31 17:01:23 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	check_duplicate(t_stack *a, t_stack *b)
{
	t_stack	*current;
	t_stack	*check;

	current = a;
	check = a->next;
	while (current->next)
	{	
		check = current->next;
		while (check)
		{
			if (check->content == current->content)
			{
				free_lsts(&a, &b);
				return (1);
			}
			check = check->next;
		}
		current = current->next;
	}
	return (0);
}

// int	ft_strcmp(char *s1, char *s2)
// {
// 	int	i;

// 	i = 0;
// 	while (s1[i] && s2[i] && s1[i] == s2[i])
// 		i++;
// 	return (s1[i] - s2[i]);
// }

// int	check_overflow(int ac, char **arg)
// {
// 	char	*ptr;
// 	int		i;
// 	int		j;

// 	j = 0;
// 	i = 1;
// 	ptr = NULL;
// 	while (i < ac)
// 	{
// 		j = 0;
// 		ptr = ft_itoa(ft_atoi(arg[i]));
// 		while (arg[i][j] && ((arg[i][j] >= 9 && arg[i][j] <= 13) ||
// 		(arg[i][j] == 32) ||
// 		(arg[i][j] == '0' && ft_strlen(arg[i]) > 1)))
// 			j++;
// 		if (ft_strcmp(ptr, arg[i] + j) != 0)
// 		{
// 			free(ptr);
// 			return (1);
// 		}
// 		free(ptr);
// 		i++;
// 	}
// 	return (0);
// }
int overflow_cmp(long sign, long nb)
{
	if (nb * sign > INT_MAX)
			return (1);
	else if (nb * sign < INT_MIN)
			return (1);
	return (0);
}

int	overflow_skip(char *s, int i)
{
	if(s[i] == '-' && !(s[i + 1] >= '0' && s[i + 1] <= '9'))
		return (1);
	if (s[i] == '+' && !(s[i + 1] >= '0' && s[i + 1] <= '9'))
		return (1);
	return (0);
}

int	checker_atoi_overflow(char *s, int *i2)
{
	int		i;
	long	nb;
	long	sign;

	i = *i2;
	sign = 1;
	nb = 0;
	while ((s[i] >= 9 && s[i] <= 13) || (s[i] == 32))
		i++;
	if (s[i] == '+')
		i++;
	if(overflow_skip(s, i))
		return (1);
	if (s[i] == '-')
		sign *= -1 + (0 * i++);
	while (s[i] >= '0' && s[i] <= '9')
	{
		nb = nb * 10 + (s[i] - '0');
		if (overflow_cmp(sign, nb) == 1)
			return (1);
		i++;
	}
	if (s[i] != '\0' && s[i] != ' ')
		return (1);
	return (*i2 = i, 0);
}

int	check_argc_overflow(int ac, char **av)
{
	int	i;
	int	i2;

	i = 1;
	while (i < ac)
	{
		i2 = 0;
		if (checker_atoi_overflow(av[i], &i2) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	check_argv_overflow(char *av)
{
	int i;
	
	i = 0;
	while (av[i])
	{
		if(checker_atoi_overflow(av, &i) == 1)
			return (1);
	}
	return (0);
}

int	check_sort(t_stack *a, t_stack *b)
{
	while (a->next)
	{
		if (a->content < a->next->content)
		{
			a = a->next;
		}
		else
			return (0);
	}
	if(b == NULL)
		return (0);
	return (1);
}

void	free_lsts(t_stack **a, t_stack **b)
{
	t_stack	*current;
	t_stack	*prev;

	current = *a;
	while (current)
	{
		prev = current;
		current = current->next;
		free(prev);
	}
	if (!*b)
		return ;
	current = *b;
	while (current)
	{
		prev = current;
		current = current->next;
		free(prev);
	}
}
