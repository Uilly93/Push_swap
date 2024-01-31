/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:15:32 by wnocchi           #+#    #+#             */
/*   Updated: 2024/01/31 15:58:33 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	if (ac > 1)
	{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;	
	if (ac == 2 && check_argv_overflow(av[1]) == 0)
		handle_string_arg(stack_a, stack_b, av);
	else if (ac > 2 && check_argc_overflow(ac, av) == 0)
		multi_args(stack_a, stack_b, ac, av);
	else
		write(2, "Error\n", 6);	
	}
	return (0);	
}
	// print_stack(&stack_a, "stack_a");
	// ft_printf("%d", check_sort(stack_a));
