/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 10:15:02 by wnocchi           #+#    #+#             */
/*   Updated: 2024/02/02 14:57:01 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr(t_stack **sa, t_stack **sb, int print)
{
	if (lst_size (*sa) > 1)
		ft_rra(sa, 0);
	if (lst_size (*sb) > 1)
		ft_rrb(sb, 0);
	if (print == 1)
		ft_printf("rrr\n");
}
