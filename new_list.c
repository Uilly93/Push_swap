/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:32:18 by wnocchi           #+#    #+#             */
/*   Updated: 2024/01/13 16:30:43 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}

int	ft_atoi(char *s)
{
	int i;
	int nb;
	int sign;

	i = 0;
	sign = 1;
	nb = 0;
	while((s[i] >= 9 && s[i] <= 13) || (s[i] == 32))
		i++;
	if((s[i] == '+') || (s[i] == '-'))
	{
		if(s[i] == '-')
			sign *= -1;
		i++;
	}
	while(s[i] >= '0' && s[i] <= '9')
	{
		nb *= 10;
		nb += (s[i] - '0');
		i++;
	}
	return (nb * sign);
}

void	print_stack(t_stack **stack, char *name){
	ft_printf("this is %s stack\n", name);
	t_stack *current = *stack;
	while(current){
		ft_printf("%d -> ", current->content);
		current = current->next;
	}
	ft_printf("%p\n", current);
}

t_stack *single_arg(char *arg)
{
	t_stack *lst;
	t_stack *node;
	int i;

	lst = NULL;
	if(!arg)
		return (NULL);
	i = 0;
	while (arg[i]){
		while (arg[i] == ' ' && arg[i] != '\0')
            i++;
		if (arg[i] == '\0')
            break;
		node = new_node(ft_atoi(arg + i));
		ft_lstadd_back(&lst, node);
		while (arg[i] != ' ' && arg[i] != '\0')
            i++;
	}
	return (lst);
}

t_stack *new_list(int ac, char **av)
{
	t_stack *lst;
	t_stack *node;
	int i;
		
	i = 1;
	lst = NULL;
	while (i < ac)
	{
		node = new_node(ft_atoi(av[i]));
		ft_lstadd_back(&lst, node);
		i++;
	}
	return (lst);
}

int main(int ac, char **av){
	t_stack *lst = NULL;
	if(ac == 2){
	lst = single_arg(av[1]);
	print_stack(&lst, "lst");
	sort_three(&lst);	
	}
	// new_list(ac, av);
	// printf("%d", (lst)->content);
	print_stack(&lst, "lst");
	return 0;
}
