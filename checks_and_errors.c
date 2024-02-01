/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_and_errors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:57:12 by wnocchi           #+#    #+#             */
/*   Updated: 2024/02/01 21:25:52 by wnocchi          ###   ########.fr       */
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

int	check_sort(t_stack *a, t_stack *b)
{
	t_stack *current;
	
	current = a;
	while (current->next)
	{
		if (current->content < current->next->content)
		{
			current = current->next;
		}
		else
			return (0);
	}
	if(b == NULL)
		return (1);
	return (0);
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
