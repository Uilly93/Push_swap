/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 10:13:52 by wnocchi           #+#    #+#             */
/*   Updated: 2024/01/13 10:14:40 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrb(t_stack **sb)
{
	t_stack	*tmp;
	t_stack	*current;
	
	tmp = NULL;
	current = *sb;
	while (current->next != NULL)
	{
		tmp = current;
		current = current->next;
	}
	tmp->next = NULL;
    current->next = *sb;
    *sb = current;
	ft_printf("rrb\n");
}
