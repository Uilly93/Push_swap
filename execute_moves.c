/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:36:00 by wnocchi           #+#    #+#             */
/*   Updated: 2024/02/02 14:57:19 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	execute_ra_rb(t_stack **a, t_stack **b, int nb)
{
	while ((*a)->content != nb && find_pos_b(*b, nb) != 0)
		ft_rr(a, b, 1);
	while ((*a)->content != nb)
		ft_ra(a, 1);
	while (find_pos_b(*b, nb) != 0)
		ft_rb(b, 1);
	ft_pb(b, a, 1);
	return (1);
}

int	execute_rra_rrb(t_stack **a, t_stack **b, int nb)
{
	while ((*a)->content != nb && find_pos_b(*b, nb) != 0)
		ft_rrr(a, b, 1);
	while ((*a)->content != nb)
		ft_rra(a, 1);
	while (find_pos_b(*b, nb) != 0)
		ft_rrb(b, 1);
	ft_pb(b, a, 1);
	return (1);
}

int	execute_ra_rrb(t_stack **a, t_stack **b, int nb)
{
	while ((*a)->content != nb)
		ft_ra(a, 1);
	while (find_pos_b(*b, nb) != 0)
		ft_rrb(b, 1);
	ft_pb(b, a, 1);
	return (1);
}

int	execute_rra_rb(t_stack **a, t_stack **b, int nb)
{
	while ((*a)->content != nb)
		ft_rra(a, 1);
	while (find_pos_b(*b, nb) != 0)
		ft_rb(b, 1);
	ft_pb(b, a, 1);
	return (1);
}
