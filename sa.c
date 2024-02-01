/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:49:09 by wnocchi           #+#    #+#             */
/*   Updated: 2024/02/01 21:31:36 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **sa, int print)
{
	int	tmp;

	if (*sa && (*sa)->next)
	{
		tmp = (*sa)->content;
		(*sa)->content = (*sa)->next->content;
		(*sa)->next->content = tmp;
	}
	if (print == 1)
		ft_printf("sa\n");
}
