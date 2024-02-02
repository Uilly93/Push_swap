/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:56:05 by wnocchi           #+#    #+#             */
/*   Updated: 2024/02/02 12:17:09 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a)
{
	if ((*a)->content > (*a)->next->content)
		ft_sa(a, 1);
}

void	sort_three(t_stack **sa)
{
	int	top;
	int	mid;
	int	bot;

	top = (*sa)->content;
	mid = (*sa)->next->content;
	bot = (*sa)->next->next->content;
	if (top < mid && mid > bot && top < bot)
	{
		ft_sa(sa, 1);
		ft_ra(sa, 1);
	}
	else if (top > mid && mid < bot && top < bot)
		ft_sa(sa, 1);
	else if (top > mid && mid > bot && top > bot)
	{
		ft_sa(sa, 1);
		ft_rra(sa, 1);
	}
	else if (top < mid && mid > bot && top > bot)
		ft_rra(sa, 1);
	else if (top > mid && mid < bot && top > bot)
		ft_ra(sa, 1);
}

void	sort_four(t_stack **a, t_stack **b)
{
	ft_pb(b, a, 1);
	sort_three(a);
	place_it(a, b);
	place_min(a);
}

void	identify_size_check_sort(t_stack **a, t_stack **b)
{
	if (lst_size(*a) == 2)
		sort_two(a);
	else if (lst_size(*a) == 3)
		sort_three(a);
	else if (lst_size(*a) == 4)
		sort_four(a, b);
	return ;
}

void	algo_sort(t_stack **a, t_stack **b)
{
	t_stack	*current;

	*b = NULL;
	if (check_sort(*a, *b) == 1)
		return ;
	identify_size_check_sort(a, b);
	if (lst_size(*a) > 4)
	{
		ft_pb(b, a, 1);
		ft_pb(b, a, 1);
		cmp_execute_case(a, b);
		place_max_b(b);
		sort_three(a);
		current = *b;
		while (current)
		{
			place_it(a, b);
			if (*b == NULL)
				break ;
		}
		place_min(a);
	}
}
