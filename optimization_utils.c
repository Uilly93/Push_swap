/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:47:50 by wnocchi           #+#    #+#             */
/*   Updated: 2024/01/28 20:50:31 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	how_many_ra_rb(t_stack **a, t_stack **b, int nb)
{
	int	move_count;

	move_count = find_index(*a, nb);
	if(find_pos_b(*b, nb) > find_index(*a, nb))
		move_count = find_pos_b(*b, nb);
	return (move_count);
}

int	how_many_rra_rrb(t_stack **a, t_stack **b, int nb)
{
	int	move_count;

	move_count = lst_size(*a) - find_index(*a, nb);
	if(lst_size(*b) - find_pos_b(*b, nb) > lst_size(*a) - find_index(*a, nb))
		move_count = lst_size(*b) - find_pos_b(*b, nb);
	return (move_count);
}

int	how_many_ra_rrb(t_stack **a, t_stack **b, int nb)
{
	int	move_count;

	move_count = find_index(*a, nb);
	if(find_pos_b(*b, nb) > 0)
		move_count += lst_size(*b) - find_pos_b(*b, nb);
	return (move_count);
}

int	how_many_rra_rb(t_stack **a, t_stack **b, int nb)
{
	int	move_count;

	move_count = lst_size(*a) - find_index(*a, nb);
	if(find_index(*b, nb) > 0)
		move_count += find_pos_b(*b, nb);
	return (move_count);
}
int	execute_ra_rb(t_stack **a, t_stack **b, int nb)
{
		while((*a)->content != nb && find_pos_b(*b, nb) != 0)
			ft_rr(a, b);
		while((*a)->content != nb)
			ft_ra(a);
		while(find_pos_b(*b, nb) != 0)
			ft_rb(b);
		ft_pb(b, a);
		return (1);
}

int	execute_rra_rrb(t_stack **a, t_stack **b, int nb)
{
		while((*a)->content != nb && find_pos_b(*b, nb) != 0)
			ft_rrr(a, b);
		while((*a)->content != nb)
			ft_rra(a);
		while(find_pos_b(*b, nb) != 0)
			ft_rrb(b);
		ft_pb(b, a);
		return (1);
}

int	execute_ra_rrb(t_stack **a, t_stack **b, int nb)
{
		while((*a)->content != nb)
			ft_ra(a);
		while(find_pos_b(*b, nb) != 0)
			ft_rrb(b);
		ft_pb(b, a);
		return (1);
}

int	execute_rra_rb(t_stack **a, t_stack **b, int nb)
{
		while((*a)->content != nb)
			ft_rra(a);
		while(find_pos_b(*b, nb) != 0)
			ft_rb(b);
		ft_pb(b, a);
		return (1);
}

int	worth_move(t_stack **a, t_stack **b)
{
	int	worth;
	t_stack *current;
	
	current = *a;
	worth = how_many_ra_rb(a, b, current->content);
	while(current)
	{
		if(how_many_rra_rb(a, b, current->content) < worth)
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
	t_stack *current;
	int		worth;
	int		i;

	current = *a;
	while (lst_size(*a) > 3)
	{
		current = *a;
		worth = worth_move(a, b);
		i = 0;
		while(i != 1)
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



