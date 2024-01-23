/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:07:52 by wnocchi           #+#    #+#             */
/*   Updated: 2024/01/23 17:05:11 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack **sa)
{
	t_stack	*current;
	int		tmp;

	current = *sa;
	while (current->next)
	{
		tmp = current->content;
		current->content = current->next->content;
		current->next->content = tmp;
		current = current->next;
	}
	ft_printf("ra\n");
}
