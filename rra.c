/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:28:29 by wnocchi           #+#    #+#             */
/*   Updated: 2024/02/02 14:23:40 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack **sa, int print)
{
	t_stack	*tmp;
	t_stack	*current;

	if (lst_size(*sa) > 1)
	{
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
		if (print == 1)
			ft_printf("rra\n");
	}
}
