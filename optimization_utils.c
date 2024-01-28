/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:47:50 by wnocchi           #+#    #+#             */
/*   Updated: 2024/01/28 10:37:55 by wnocchi          ###   ########.fr       */
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
void	execute_ra_rb(t_stack **a, t_stack **b, int nb)
{
	int moves;
	
	moves = how_many_ra_rb(a, b, nb);
	while(moves > 0)
	{
		while((*a)->content != nb || find_pos_b(a, b) != 0){
			ft_rr(a, b);
			moves = -2;
		}
		if((*a)->content != nb){
			ft_ra(a);
			moves--;
		}
		if(find_pos_b(*a, nb) != 0){
			ft_rb(b);
			moves--;
		}
	}
}