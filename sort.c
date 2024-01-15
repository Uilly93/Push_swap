/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:56:05 by wnocchi           #+#    #+#             */
/*   Updated: 2024/01/15 18:47:36 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_stack **sa)
{
	int top;
	int mid;
	int bot;

	top = (*sa)->content;
	mid = (*sa)->next->content;
	bot = (*sa)->next->next->content;
	if (top < mid && top < bot && top < bot)
	{
		ft_sa(sa);
		ft_ra(sa);
	}
	else if (top > mid && mid < bot && top < bot)
		ft_sa(sa);
	else if (top > mid && mid > bot && top > bot)
	{
		ft_rra(sa);
		ft_rra(sa);
	}
	else if (top < mid && mid > bot && top > bot)
		ft_rra(sa);
	else if (top > mid && mid < bot && top > bot)
		ft_ra(sa);
}


int	ft_min(t_stack *s)
{
	t_stack *current;
	int min;

	current = s;
	min = current->content;
	while (current)
	{
		if (current->content < min)
			min = current->content;
		current = current->next;
	}
	return (min);
}

int	ft_max(t_stack *s)
{
	t_stack *current;
	int max;

	current = s;
	max = current->content;
	while (current)
	{
		if (current->content < max)
			max = current->content;
		current = current->next;
	}
	return (max);
}
int *lst_last(t_stack *s)
{
	t_stack *current;
	int tmp;
	
	current = s;
	tmp = NULL;
	while (current)
	{
		tmp = current->content;
		current = current->next;
	}
	return(tmp);
}

int	ft_pos(t_stack *s, int nb)
{
	int i;
	t_stack *current;
	
	current = s;
	i = 1;
	if (nb > current->content && nb < lst_last(current)
	while(current->next)
	{
		if(nb > current->content && nb < current->next->content )
		current = current->next;
		i++;
	}
	return 0;
}
t_stack	*check_closest(t_stack *s, int nb)
{
	t_stack *current;
	t_stack *tmp;
	int closest;
	
	current = s;
	tmp = NULL;
	while(current)
	{
		closest = current->content - nb;
		current = current->next;
		if(closest < 0)
			closest *= -1;
		if(current->content - nb < closest && current->content - nb >= 0)
		{
			closest = current->content - nb;
			tmp->content = current->content;
		}
	}
	return (tmp);
}


void	sort_five(t_stack **sa, t_stack **sb)
{
	t_stack *current;
	t_stack *current_b;

	current = *sa;
	ft_pb(sa, sb);
	ft_pb(sa, sb);
	current_b = *sb;
	sort_three(sa);
	while(current)
	{
		
	}
}
