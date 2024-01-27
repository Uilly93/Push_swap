/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:42:29 by wnocchi           #+#    #+#             */
/*   Updated: 2024/01/27 16:33:46 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_optimal_move_for_b(t_stack **a, t_stack **b)
{
	t_stack *current;
	int		pos;
	int		cost;
	// int		costless;

	cost = 0;
	current = *a;
	pos = find_pos_b(*b, current->content);
	while(current && cost < (lst_size(*a) / 2))
	{
		if(find_pos_b(*b, current->content) < pos + cost)
			pos = find_pos_b(*b, current->content);
		cost++;
		current = current->next;
	}
	// while(cost > 0)
	// {
	// 	ft_ra(a);
	// 	cost--;
	// }
	return (pos + cost);
}



// int	how_many_moves(t_stack *a, t_stack *b)
// {
// 	t_stack	*current;
// 	t_stack	*current_b;
// 	int		nb;

// 	nb = 0;
// 	current = a;
// 	current_b = b;
	
// }

int	find_index(t_stack *s, int nb)
{
	int i;
	t_stack *current;
	
	i = 0;
	current = s;
	while(current)
	{
		if(current->content == nb)
			return(i);
		current = current->next;
		i++;
	}
	return(i);
}

// int	lower_nb(t_stack *s, int nb)
// {
// 	t_stack	*current;
// 	int		res;
	
// 	if(nb == ft_min(s))
		
// 	res = nb - 1;
// 	current = s;
// 	while(current)
// 	{
// 		if(current->content == res)
// 			return(res);
// 		res--;
// 		current = current->next;
// 	}
// 	return (res);
// }


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