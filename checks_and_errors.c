/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_and_errors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:57:12 by wnocchi           #+#    #+#             */
/*   Updated: 2024/01/25 11:52:25 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	global_checks(t_stack *a, t_stack *b)
{
	if (check_duplicate(a, b) == 1)
	{
		display_error();
		return (1);
	}
	return (0);
}

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

int	display_error(void)
{
	write(2, "Error\n", 7);
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
