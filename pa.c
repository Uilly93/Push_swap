/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:16:02 by wnocchi           #+#    #+#             */
/*   Updated: 2024/01/23 17:06:52 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack **sa, t_stack **sb)
{
	t_stack	*start_a;
	t_stack	*start_b;

	if (!*sb)
		return ;
	start_a = *sa;
	start_b = (*sb)->next;
	*sa = *sb;
	(*sa)->next = start_a;
	*sb = start_b;
	ft_printf("pa\n");
}
