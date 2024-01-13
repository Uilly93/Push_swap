/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:14:23 by wnocchi           #+#    #+#             */
/*   Updated: 2024/01/11 11:23:30 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb(t_stack **sb, t_stack **sa)
{
	t_stack *start_a;
	t_stack *start_b;
	
	if(!*sa)
		return;
	start_b = *sb;
	start_a = (*sa)->next;
	*sb = *sa;
	(*sb)->next = start_b;
	*sa = start_a;
	ft_printf("pb\n");
}
