/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:56:05 by wnocchi           #+#    #+#             */
/*   Updated: 2024/01/22 16:26:06 by wnocchi          ###   ########.fr       */
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
	if (top < mid && mid > bot && top < bot)
	{
		ft_sa(sa);
		ft_ra(sa);
	}
	else if (top > mid && mid < bot && top < bot)
		ft_sa(sa);
	else if (top > mid && mid > bot && top > bot)
	{
		ft_sa(sa);
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
		if (current->content > max)
			max = current->content;
		current = current->next;
	}
	return (max);
}
int last_content(t_stack *s)
{
	t_stack *current;
	// int tmp;

	current = s;
	// tmp = 0;
	while (current->next)
	{
		// tmp = current->content;
		current = current->next;
	}
	return(current->content);
}

int	find_pos(t_stack *s, int nb)
{
	int i;
	t_stack *current;
	
	current = s;
	i = 1;
	if (nb < current->content && nb > last_content(current))
		return (0);
	while(current->next)
	{
		if(nb > current->content && nb < current->next->content)
			return (i);
		current = current->next;
		i++;
	}
	return (i);
}

int	find_pos_b(t_stack *s, int nb)
{
	int i;
	t_stack *current;
	
	current = s;
	i = 1;
	if (nb > current->content && nb < last_content(current))
		return (0);
	while(current->next)
	{
		if(nb < current->content && nb > current->next->content)
			return (i);
		current = current->next;
		i++;
	}
	return (i);
}

void	place_max(t_stack **s)
{
	if (find_pos(*s, ft_max(*s)) <= lst_size(*s) / 2)
	{
		while ((*s)->content != ft_max(*s))
			ft_ra(s);
	}
	else
	{
		while ((*s)->content != ft_max(*s))
			ft_rra(s);
	}
}

void	place_it(t_stack **a, t_stack **b)
{
	int pos;
	int	pos_b;
	
	pos = find_pos(*a, (*b)->content);
	if(((*b)->content > ft_max(*a)) || ((*b)->content < ft_min(*a)))
		place_min(a);
	else if (pos < lst_size(*a) / 2)
	{
		// ft_printf("content is %d | pos is : %d\n",(*b)->content, pos);
		while(pos > 0)
		{
			ft_ra(a); // rotate vers le haut
			pos--;
		}
		// print_stack(a, "stack_a");
		// print_stack(b, "stack_a");
	}
	else// if(pos > lst_size(*a) / 2)
	{
		pos_b = lst_size(*a) - pos;
		// ft_printf("content is %d | pos_b is : %d\n",(*b)->content, pos_b);
		while(pos_b > 0)
		{
			ft_rra(a); //rotate vers le bas
			pos_b--;
		}
		// print_stack(a, "stack_a");
		// print_stack(b, "stack_b"); // 6 lines

	}
	ft_pa(a, b);
}

void	place_it_b(t_stack **b, t_stack **a)
{
	int pos;
	int	pos_b;
	
	pos = find_pos_b(*b, (*a)->content);
	if ((*b)->content > ft_max(*a))
		place_min(a);
	if (pos < (lst_size(*b) / 2))
	{
		// ft_printf("content is %d | pos is : %d\n",(*b)->content, pos);
		while(pos > 0)
		{
			ft_rb(b); // rotate vers le haut
			pos--;
		}
		// print_stack(a, "stack_a");
		// print_stack(b, "stack_a");
	}
	else// if(pos > (lst_size(*a) / 2))
	{
		pos_b = lst_size(*b) - pos;
		// ft_printf("content is %d | pos_b is : %d\n",(*b)->content, pos_b);
		while(pos_b > 0)
		{
			ft_rrb(b); //rotate vers le bas
			pos_b--;
		}
		// print_stack(a, "stack_a");
		// print_stack(b, "stack_b");

	}
	// print_stack(a, "stack_a");
	// print_stack(b, "stack_b");
	ft_pb(b, a);
	// print_stack(a, "stack_a");
	// print_stack(b, "stack_b");

}
void	place_min_b(t_stack **s)
{
	// printf("find_pos: %d\n", find_pos(*s, ft_min(*s)));
	if (find_pos(*s, ft_min(*s)) < lst_size(*s) / 2)
	{
		while ((*s)->content != ft_min(*s))
			ft_rb(s);
	}
	else //if (find_pos(*s, ft_min(*s)) > lst_size(*s) / 2)
	{
		while ((*s)->content != ft_min(*s))
			ft_rrb(s);
	}
}
void	place_min(t_stack **s)
{
	// printf("find_pos: %d\n", find_pos(*s, ft_min(*s)));
	if (find_pos(*s, ft_min(*s)) < lst_size(*s) / 2)
	{
		while ((*s)->content != ft_min(*s))
			ft_ra(s);
	}
	else //if (find_pos(*s, ft_min(*s)) > lst_size(*s) / 2)
	{
		while ((*s)->content != ft_min(*s))
			ft_rra(s);	
	}
}
void	sort_two(t_stack **a)
{
	if((*a)->content > (*a)->next->content)
		ft_sa(a);
}

void	sort_four(t_stack **a, t_stack **b)
{
	ft_pb(b, a);
	sort_three(a);
	place_it(a, b);
	place_min(a);
}

void	identify_size_check_sort(t_stack **a, t_stack **b)
{
	if (check_sort(*a, *b) == 1)
		return ;
	else if(lst_size(*a) == 2)
		sort_two(a);
	else if(lst_size(*a) == 3)
		sort_three(a);
	else if (lst_size(*a) == 4)
		sort_four(a, b);
}


void	algo_sort(t_stack **a, t_stack **b)
{
	t_stack *current;
	identify_size_check_sort(a, b);
	if (lst_size(*a) > 4)
	{
		ft_pb(b, a);
		ft_pb(b, a);
		while(lst_size(*a) > 3)
		{
			place_it_b(b, a);
			// print_stack(a, "stack _A is");
			// print_stack(b, "stack _B is");
		}
		// print_stack(a, "BEFORE SORT THREE --->");
		sort_three(a);
		// print_stack(a, "AFTER SORT THREE --->");
		current = *b;
		while(current)
		{
			place_it(a, b);
			// print_stack(a, "stack _a is");
			// print_stack(b, "stack _b is");
			if(*b == NULL)
				break;
		}
		place_min(a);
	}
}

// void	other_sort(t_stack **a, t_stack **b)
// {
// 	t_stack *current;

// 	current = *a;
// 	while(current)
// 	{
// 		if(current == NULL)
// 			break;
// 		place_min(a);
// 		ft_pb(b, a);
// 	}
// 	while(*b)
// 	{
// 		if(*b == NULL)
// 			break;
// 		ft_pa(a, b);
// 	}
// }

int	check_sort(t_stack *a, t_stack *b)
{
	while(a->next)
	{
		if(a->content < a->next->content)
		{
			a = a->next;
		}
		else
			return (0);
	}
	if (b == NULL)
		return (1);
	return (0);
}


// t_stack	*check_closest(t_stack *s, int nb)
// {
// 	t_stack *current;
// 	t_stack *tmp;
// 	int closest;
	
// 	current = s;
// 	tmp = NULL;
// 	while(current)
// 	{
// 		closest = current->content - nb;
// 		current = current->next;
// 		if(closest < 0)
// 			closest *= -1;
// 		if(current->content - nb < closest && current->content - nb >= 0)
// 		{
// 			closest = current->content - nb;
// 			tmp->content = current->content;
// 		}
// 	}
// 	return (tmp);
// }

// void	min_max(t_stack **a, t_stack **b)
// {
// 	if((*b)->content == ft_min(*a))
// 		ft_pa(a, b);
// 	else if((*b)->content == ft_max(*a))
// 	{
// 		ft_pa(a, b);
// 		ft_ra(a);
// 	}
// }


// void	sort_above_four(t_stack **sa, t_stack **sb)
// {
// 	t_stack *current;
// 	t_stack *current_b;

// 	current = *sa;
// 	int pos;
// 	ft_pb(sa, sb);
// 	ft_pb(sa, sb);
// 	current_b = *sb;
// 	sort_three(sa);
// 	while(current_b)
// 	{
// 		pos = find_pos(*sa, current_b->content);
// 		if(pos < lst_size(current) / 2)
// 		{
// 			while(pos >= 0)
// 			{
// 				ft_ra(sa);
// 				pos--;
// 			}
// 			ft_pa(sa, sb);
// 		}
// 		current_b = current_b->next;
// 	}
// }
