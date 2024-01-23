/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:15:32 by wnocchi           #+#    #+#             */
/*   Updated: 2024/01/23 17:20:17 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 2)
		handle_string_arg(stack_a, stack_b, av);
	else if (ac > 2)
		handle_multi_args(stack_a, stack_b, ac, av);
	else
	{
		display_error();
		free_lsts(&stack_a, &stack_b);
	}
}
