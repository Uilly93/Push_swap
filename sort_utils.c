/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:38:19 by wnocchi           #+#    #+#             */
/*   Updated: 2024/01/29 09:37:57 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	place_it(t_stack **a, t_stack **b)
{
	int	pos;
	int	pos_b;

	pos = find_pos(*a, (*b)->content);
	pos_b = lst_size(*a) - pos;
	if (((*b)->content > ft_max(*a)) || ((*b)->content < ft_min(*a)))
		place_min(a);
	determine_side_a(a, pos, pos_b);
	ft_pa(a, b);
}

void	place_min(t_stack **s)
{
	if (find_pos(*s, ft_min(*s)) < (lst_size(*s) / 2))
	{
		while ((*s)->content != ft_min(*s))
			ft_ra(s);
	}
	else
	{
		while ((*s)->content != ft_min(*s))
			ft_rra(s);
	}
}

void	place_max_b(t_stack **s)
{
	if (find_pos(*s, ft_max(*s)) < (lst_size(*s) / 2))
	{
		while ((*s)->content != ft_max(*s))
			ft_rb(s);
	}
	else
	{
		while ((*s)->content != ft_max(*s))
			ft_rrb(s);
	}
}
