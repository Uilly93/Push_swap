/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_and_errors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:57:12 by wnocchi           #+#    #+#             */
/*   Updated: 2024/01/29 17:49:08 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	check_overflow(int ac, char **arg)
{
	char	*ptr;
	int		i;
	int		j;

	j = 0;
	i = 1;
	ptr = NULL;
	while (i < ac)
	{
		j = 0;
		ptr = ft_itoa(ft_atoi(arg[i]));
		while (arg[i][j] && ((arg[i][j] >= 9 && arg[i][j] <= 13) ||
		(arg[i][j] == 32) ||
		(arg[i][j] == '0' && ft_strlen(arg[i]) > 1)))
			j++;
		if (ft_strcmp(ptr, arg[i] + j) != 0)
		{
			free(ptr);
			return (1);
		}
		free(ptr);
		i++;
	}
	return (0);
}

int	check_sort(t_stack *a)
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
