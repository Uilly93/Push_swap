/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:38:19 by wnocchi           #+#    #+#             */
/*   Updated: 2024/01/24 11:02:23 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	place_it(t_stack **a, t_stack **b)
{
	int	pos;
	int	pos_b;

	pos = find_pos(*a, (*b)->content);
	if (((*b)->content > ft_max(*a)) || ((*b)->content < ft_min(*a)))
		place_min(a);
	else if (pos < lst_size(*a) / 2)
	{
		while (pos > 0)
		{
			ft_ra(a);
			pos--;
		}
	}
	else
	{
		pos_b = lst_size(*a) - pos;
		while (pos_b > 0)
		{
			ft_rra(a);
			pos_b--;
		}
	}
	ft_pa(a, b);
}

void	place_it_b(t_stack **b, t_stack **a)
{
	int	pos;
	int	pos_b;

	pos = find_pos_b(*b, (*a)->content);
	if ((*a)->content > ft_max(*b))
		place_min_b(b);
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
		pos_b = lst_size(*b) - pos;
		while (pos_b > 0)
		{
			ft_rrb(b);
			pos_b--;
		}
	}
	ft_pb(b, a);
}

void	place_min_b(t_stack **s)
{
	if (find_pos(*s, ft_min(*s)) < lst_size(*s) / 2)
	{
		while ((*s)->content != ft_min(*s))
			ft_rb(s);
	}
	else
	{
		while ((*s)->content != ft_min(*s))
			ft_rrb(s);
	}
}

void	place_min(t_stack **s)
{
	if (find_pos(*s, ft_min(*s)) < lst_size(*s) / 2)
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
	if (find_pos(*s, ft_max(*s)) < lst_size(*s) / 2)
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