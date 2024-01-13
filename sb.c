/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:11:03 by wnocchi           #+#    #+#             */
/*   Updated: 2024/01/13 16:36:44 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sb(t_stack **sb)
{
	int tmp;

	if (*sb && (*sb)->next)
	{
		tmp = (*sb)->content;
		(*sb)->content = (*sb)->next->content;
		(*sb)->next->content = tmp;
	}
	ft_printf("sb\n");
}
