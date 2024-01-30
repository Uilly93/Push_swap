/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:36:18 by wnocchi           #+#    #+#             */
/*   Updated: 2024/01/30 15:35:23 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	return_error_exit(t_stack **a, t_stack **b)
{
	write(2, "Error\n", 6);
	free_lsts(a, b);
	exit(1);
}
int	string_arg_to_list(t_stack *stack_a, t_stack *stack_b, char **av)
{
	stack_a = single_arg(av[1]);
	if ((!av) || (*av[1] == 0) || check_duplicate(stack_a, stack_b) == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}
	// print_stack(&stack_a, "stack_a");

int	mult_arg_to_list(t_stack *stack_a, t_stack *stack_b, int ac, char **av)
{
	stack_a = argv_list(ac, av);
	if ((check_duplicate(stack_a, stack_b)) || (check_overflow(ac, av)))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}


void	execute_instructions(t_stack **a, t_stack **b, char *instruction)
{
	instruction = get_next_line(0);
	if (ft_strcmp(instruction, "ra\n"))
		ft_ra(a);
	else if (ft_strcmp(instruction, "rb\n"))
		ft_rb(b);
	else if (ft_strcmp(instruction, "rr\n"))
		ft_rr(a, b);
	else if (ft_strcmp(instruction, "rra\n"))
		ft_rra(a);
	else if (ft_strcmp(instruction, "rrb\n"))
		ft_rrb(b);
	else if (ft_strcmp(instruction, "rrr\n"))
		ft_rrr(a, b);
	else if (ft_strcmp(instruction, "pa\n"))
		ft_pa(a, b);
	else if (ft_strcmp(instruction, "pb\n"))
		ft_pb(b, a);
	else if (ft_strcmp(instruction, "sa\n"))
		ft_sa(a);
	else if (ft_strcmp(instruction, "sb\n"))
		ft_sb(a);
	else if (ft_strcmp(instruction, "ss\n"))
		ft_ss(a, b);
	else
		return_error_exit(a, b);
}

void	check_output(t_stack **a, t_stack **b, char *insctuction)
{
	
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (check_overflow(ac, av) == 1)
		return(write(2, "Error\n", 6), 1);
	if (ac == 2)
	{
		handle_string_arg(stack_a, stack_b, av);
		algo_sort(&stack_a, &stack_b);
	}
	else if (ac > 2)
	{
		multi_args(stack_a, stack_b, ac, av);
		algo_sort(&stack_a, &stack_b);
	}
	else if (ac == 1)
		write(2, "Error\n", 6);
	free_lsts(&stack_a, &stack_b);
	return (0);
}

