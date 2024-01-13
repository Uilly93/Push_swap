/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:44:29 by wnocchi           #+#    #+#             */
/*   Updated: 2024/01/09 16:00:17 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int nb)
{
	t_stack	*node;
	
	node = malloc(sizeof(t_stack));
	node->content = nb;
	node->next = NULL;
	return(node);
}