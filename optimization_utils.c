/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:47:50 by wnocchi           #+#    #+#             */
/*   Updated: 2024/01/27 16:33:13 by wnocchi          ###   ########.fr       */
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
	if(lst_size(*b) - find_pos_b(*b, nb) > find_index(*a, nb))
		move_count = lst_size(*b) - find_pos_b(*b, nb);
	return (move_count);
}

int	how_many_rra_rb(t_stack **a, t_stack **b, int nb)
{
	int	move_count;

	move_count = lst_size(*a) - find_index(*a, nb);
	if(find_index(*b, nb) > lst_size(*a) - find_pos_b(*a, nb))
		move_count = find_index(*b, nb);
	return (move_count);
}