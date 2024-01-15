/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:44:29 by wnocchi           #+#    #+#             */
/*   Updated: 2024/01/15 10:48:09 by wnocchi          ###   ########.fr       */
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

int	lst_size(t_stack *lst)
{
	t_stack *current;
	int i;

	current = lst;
	i = 0;
	while(current)
	{
		current = current->next;
		i++;
	}
	return (i);
}