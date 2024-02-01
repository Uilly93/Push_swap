/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:13:08 by wnocchi           #+#    #+#             */
/*   Updated: 2024/02/01 18:36:37 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ss(t_stack **sa, t_stack **sb, int print)
{
	int	tmp;

	if (*sa && (*sa)->next && *sb && (*sb)->next)
	{
		tmp = (*sa)->content;
		(*sa)->content = (*sa)->next->content;
		(*sa)->next->content = tmp;
		tmp = (*sb)->content;
		(*sb)->content = (*sb)->next->content;
		(*sb)->next->content = tmp;
	}
	if (print == 1)
		ft_printf("ss\n");
}
