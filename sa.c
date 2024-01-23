/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:49:09 by wnocchi           #+#    #+#             */
/*   Updated: 2024/01/23 17:01:25 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **sa)
{
	int	tmp;

	if (*sa && (*sa)->next)
	{
		tmp = (*sa)->content;
		(*sa)->content = (*sa)->next->content;
		(*sa)->next->content = tmp;
	}
	ft_printf("sa\n");
}
