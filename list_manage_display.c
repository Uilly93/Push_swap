/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manage_display.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:17:35 by wnocchi           #+#    #+#             */
/*   Updated: 2024/01/29 11:46:50 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*single_arg(char *arg)
{
	t_stack	*lst;
	t_stack	*node;
	int		i;

	lst = NULL;
	if ((!arg) || (*arg == 0))
		return (NULL);
	i = 0;
	while (arg[i])
	{
		while (arg[i] == ' ' && arg[i] != '\0')
			i++;
		if (arg[i] == '\0')
			break ;
		node = new_node(ft_atoi(arg + i));
		ft_lstadd_back(&lst, node);
		while (arg[i] != ' ' && arg[i] != '\0')
			i++;
	}
	return (lst);
}

t_stack	*argv_list(int ac, char **av)
{
	t_stack	*lst;
	t_stack	*node;
	int		i;

	i = 1;
	node = NULL;
	lst = NULL;
	while (i < ac)
	{
		node = new_node(ft_atoi(av[i]));
		ft_lstadd_back(&lst, node);
		i++;
	}
	return (lst);
}

int	handle_string_arg(t_stack *stack_a, t_stack *stack_b, char **av)
{
	stack_a = single_arg(av[1]);
	if ((!av) || (*av[1] == 0) || check_duplicate(stack_a, stack_b))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	algo_sort(&stack_a, &stack_b);
	free_lsts(&stack_a, &stack_b);
	return (0);
}
	// print_stack(&stack_a, "stack_a");

int	multi_args(t_stack *stack_a, t_stack *stack_b, int ac, char **av)
{
	stack_a = argv_list(ac, av);
	check_duplicate(stack_a, stack_b);
	{
		write(2, "Error\n", 6);
		return (1);
	}
	algo_sort(&stack_a, &stack_b);
	free_lsts(&stack_a, &stack_b);
	return (0);
}
	// print_stack(&stack_a, "stack_a");
	// ft_printf("%d\n", check_sort(stack_a));

void	print_stack(t_stack **stack, char *name)
{
	t_stack	*current;

	current = *stack;
	ft_printf("this is %s stack\n", name);
	while (current)
	{
		ft_printf("[%d] --> ", current->content);
		current = current->next;
	}
	ft_printf("%p\n", current);
}
// enlever avant de push