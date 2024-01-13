/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:28:29 by wnocchi           #+#    #+#             */
/*   Updated: 2024/01/13 10:14:32 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack **sa)
{
	t_stack	*tmp;
	t_stack	*current;
	
	tmp = NULL;
	current = *sa;
	while (current->next != NULL)
	{
		tmp = current;
		current = current->next;
	}
	tmp->next = NULL;
    current->next = *sa;
    *sa = current;
	ft_printf("rra\n");
}
