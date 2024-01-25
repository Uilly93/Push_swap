/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:42:29 by wnocchi           #+#    #+#             */
/*   Updated: 2024/01/25 16:26:05 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_optimal_move_for_b(t_stack *a, t_stack *b)
{
	t_stack *current;
	int		pos;
	int		cost;
	int		costless;

	cost = 0;
	current = a;
	pos = find_pos_b(b, current->content);
	while(current && cost < (lst_size(a) / 2) - 1)
	{
		if(find_pos_b(b, a->content) < pos + cost)
			pos = find_pos_b(b, current->content);
		cost++;
		current = current->next;
	}
	// while(cost > 0)
	// {
	// 	ft_ra(&a);
	// 	cost--;
	// }
	return (pos);
}



void	determine_side_b(t_stack **b, int pos, int pos_b)
{
	if (pos < (lst_size(*b) / 2))
	{
		while (pos > 0)
		{
			ft_rb(b);
			pos--;
		}
	}
	else
	{
		while (pos_b > 0)
		{
			ft_rrb(b);
			pos_b--;
		}
	}
}

void	determine_side_a(t_stack **a, int pos, int pos_b)
{
	if (pos < lst_size(*a) / 2)
	{
		while (pos > 0)
		{
			ft_ra(a);
			pos--;
		}
	}
	else
	{
		while (pos_b > 0)
		{
			ft_rra(a);
			pos_b--;
		}
	}
}