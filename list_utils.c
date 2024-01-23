/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:44:29 by wnocchi           #+#    #+#             */
/*   Updated: 2024/01/23 16:57:49 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int nb)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	node->content = nb;
	node->next = NULL;
	return (node);
}

int	lst_size(t_stack *lst)
{
	t_stack	*current;
	int		i;

	current = lst;
	i = 0;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*current;
	int		i;

	if (!lst)
		return (0);
	current = lst;
	i = 0;
	while (current->next)
	{
		i++;
		current = current->next;
	}
	return (current);
}

int	last_content(t_stack *s)
{
	t_stack	*current;

	current = s;
	while (current->next)
	{
		current = current->next;
	}
	return (current->content);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}
