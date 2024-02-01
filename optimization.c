/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:42:29 by wnocchi           #+#    #+#             */
/*   Updated: 2024/02/01 18:38:40 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index(t_stack *s, int nb)
{
	int		i;
	t_stack	*current;

	i = 0;
	current = s;
	while (current)
	{
		if (current->content == nb)
			return (i);
		current = current->next;
		i++;
	}
	return (i);
}

void	determine_side_a(t_stack **a, int pos, int pos_b)
{
	if (pos < lst_size(*a) / 2)
	{
		while (pos > 0)
		{
			ft_ra(a, 1);
			pos--;
		}
	}
	else
	{
		while (pos_b > 0)
		{
			ft_rra(a, 1);
			pos_b--;
		}
	}
}

int	worth_move(t_stack **a, t_stack **b)
{
	int		worth;
	t_stack	*current;

	current = *a;
	worth = how_many_ra_rb(a, b, current->content);
	while (current)
	{
		if (how_many_rra_rb(a, b, current->content) < worth)
			worth = how_many_rra_rb(a, b, current->content);
		if (how_many_rra_rrb(a, b, current->content) < worth)
			worth = how_many_rra_rrb(a, b, current->content);
		if (how_many_ra_rrb(a, b, current->content) < worth)
			worth = how_many_ra_rrb(a, b, current->content);
		if (how_many_ra_rb(a, b, current->content) < worth)
			worth = how_many_ra_rb(a, b, current->content);
		current = current->next;
	}
	return (worth);
}

void	cmp_execute_case(t_stack **a, t_stack **b)
{
	t_stack	*current;
	int		worth;
	int		i;

	current = *a;
	while (lst_size(*a) > 3)
	{
		current = *a;
		worth = worth_move(a, b);
		i = 0;
		while (i != 1)
		{
			if (worth == how_many_ra_rrb(a, b, current->content))
				i = execute_ra_rrb(a, b, current->content);
			else if (worth == how_many_rra_rrb(a, b, current->content))
				i = execute_rra_rrb(a, b, current->content);
			else if (worth == how_many_ra_rb(a, b, current->content))
				i = execute_ra_rb(a, b, current->content);
			else if (worth == how_many_rra_rb(a, b, current->content))
				i = execute_rra_rb(a, b, current->content);
			else
				current = current->next;
		}
	}
}
