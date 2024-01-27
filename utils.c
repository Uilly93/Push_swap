/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:32:18 by wnocchi           #+#    #+#             */
/*   Updated: 2024/01/27 15:45:40 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *s)
{
	int	i;
	int	nb;
	int	sign;

	i = 0;
	sign = 1;
	nb = 0;
	while ((s[i] >= 9 && s[i] <= 13) || (s[i] == 32))
		i++;
	if ((s[i] == '+') || (s[i] == '-'))
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		nb *= 10;
		nb += (s[i] - '0');
		i++;
	}
	return (nb * sign);
}

int	ft_min(t_stack *s)
{
	t_stack	*current;
	int		min;

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
	t_stack	*current;
	int		max;

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

int	find_pos(t_stack *s, int nb)
{
	int		i;
	t_stack	*current;

	current = s;
	i = 1;
	if (nb < current->content && nb > last_content(current))
		return (0);
	while (current->next)
	{
		if (nb > current->content && nb < current->next->content)
			return (i);
		current = current->next;
		i++;
	}
	return (i);
}

int	find_pos_b(t_stack *s, int nb)
{
	int		i;
	t_stack	*current;

	current = s;
	i = 1;
	if (nb > current->content && nb < last_content(current))
		return (0);
	if(nb > ft_max(s) || nb < ft_min(s))
		return (find_index(s, ft_max(s)));
	while (current->next)
	{
		if (nb < current->content && nb > current->next->content)
			return (i);
		current = current->next;
		i++;
	}
	return (i);
}
