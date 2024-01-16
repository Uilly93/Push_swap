/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:56:05 by wnocchi           #+#    #+#             */
/*   Updated: 2024/01/16 14:58:29 by wnocchi          ###   ########.fr       */
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
int lst_last(t_stack *s)
{
	t_stack *current;
	int tmp;

	current = s;
	tmp = 0;
	while (current)
	{
		tmp = current->content;
		current = current->next;
	}
	return(tmp);
}

int	find_index(t_stack *s, int nb)
{
	int i;
	t_stack
}

int	find_pos(t_stack *s, int nb)
{
	int i;
	t_stack *current;
	
	current = s;
	i = 1;
	if (nb > current->content && nb < lst_last(current))
		return (0);
	while(current->next)
	{
		if(nb > current->content && nb < current->next->content)
			break;
		current = current->next;
		i++;
	}
	return (i);
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
void	algo_sort(t_stack **a, t_stack **b)
{
	t_stack *current;
	t_stack *current_b;
	int pos;

	current = *a;
	current_b = *b;
	while(current_b)
	{
		pos = find_pos(*a, current_b->content);
		if(pos < lst_size(current) / 2)
		{
			while(pos >= 0)
			{
				ft_ra(a);
				pos--;
			}
			ft_pa(a, b);
		}
		current_b = current_b->next;
	}
}

void	sort_above_four(t_stack **sa, t_stack **sb)
{
	t_stack *current;
	t_stack *current_b;

	current = *sa;
	int pos;
	ft_pb(sa, sb);
	ft_pb(sa, sb);
	current_b = *sb;
	sort_three(sa);
	while(current_b)
	{
		pos = find_pos(*sa, current_b->content);
		if(pos < lst_size(current) / 2)
		{
			while(pos >= 0)
			{
				ft_ra(sa);
				pos--;
			}
			ft_pa(sa, sb);
		}
		current_b = current_b->next;
	}
}
