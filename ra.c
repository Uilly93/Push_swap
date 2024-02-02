/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:07:52 by wnocchi           #+#    #+#             */
/*   Updated: 2024/02/02 14:23:01 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack **sa, int print)
{
	t_stack	*current;
	int		tmp;

	if (lst_size (*sa) > 1)
	{
		current = *sa;
		while (current->next)
		{
			tmp = current->content;
			current->content = current->next->content;
			current->next->content = tmp;
			current = current->next;
		}
		if (print == 1)
			ft_printf("ra\n");
	}
}
