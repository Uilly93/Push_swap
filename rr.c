/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:14:54 by wnocchi           #+#    #+#             */
/*   Updated: 2024/02/01 21:31:16 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rr(t_stack **sa, t_stack **sb, int print)
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
	current = *sb;
	while (current->next)
	{
		tmp = current->content;
		current->content = current->next->content;
		current->next->content = tmp;
		current = current->next;
	}
	if (print == 1)
		ft_printf("rr\n");
}
