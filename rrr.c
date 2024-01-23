/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 10:15:02 by wnocchi           #+#    #+#             */
/*   Updated: 2024/01/23 17:02:21 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr(t_stack **sa, t_stack **sb)
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
	ft_printf("rrr\n");
}
