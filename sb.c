/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:11:03 by wnocchi           #+#    #+#             */
/*   Updated: 2024/02/01 18:36:19 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sb(t_stack **sb, int print)
{
	int	tmp;

	if (*sb && (*sb)->next)
	{
		tmp = (*sb)->content;
		(*sb)->content = (*sb)->next->content;
		(*sb)->next->content = tmp;
	}
	if (print == 1)
		ft_printf("sb\n");
}
