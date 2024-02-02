/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:03:59 by wnocchi           #+#    #+#             */
/*   Updated: 2024/02/02 14:12:07 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rb(t_stack **sb, int print)
{
	t_stack	*current;
	int		tmp;

	if (lst_size(*sb) > 1)
	{
		current = *sb;
		while (current->next)
		{
			tmp = current->content;
			current->content = current->next->content;
			current->next->content = tmp;
			current = current->next;
		}
		if (print == 1)
			ft_printf("rb\n");
	}
}
