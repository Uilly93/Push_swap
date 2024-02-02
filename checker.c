/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:36:18 by wnocchi           #+#    #+#             */
/*   Updated: 2024/02/02 14:57:31 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GNL/get_next_line.h"
#include "push_swap.h"

// void	return_error_exit(void)
// {
// 	write(2, "Error\n", 6);
// }

void	execute_and_cmp(t_stack **a, t_stack **b, char *instruction)
{
	if (ft_strcmp(instruction, "ra\n") == 0)
		ft_ra(a, 0);
	else if (ft_strcmp(instruction, "rb\n") == 0)
		ft_rb(b, 0);
	else if (ft_strcmp(instruction, "rr\n") == 0)
		ft_rr(a, b, 0);
	else if (ft_strcmp(instruction, "rra\n") == 0)
		ft_rra(a, 0);
	else if (ft_strcmp(instruction, "rrb\n") == 0)
		ft_rrb(b, 0);
	else if (ft_strcmp(instruction, "rrr\n") == 0)
		ft_rrr(a, b, 0);
	else if (ft_strcmp(instruction, "pa\n") == 0)
		ft_pa(a, b, 0);
	else if (ft_strcmp(instruction, "pb\n") == 0)
		ft_pb(b, a, 0);
	else if (ft_strcmp(instruction, "sa\n") == 0)
		ft_sa(a, 0);
	else if (ft_strcmp(instruction, "sb\n") == 0)
		ft_sb(a, 0);
	else if (ft_strcmp(instruction, "ss\n") == 0)
		ft_ss(a, b, 0);
	else
		(write(2, "Error\n", 6));
}

int	check_output(t_stack **a, t_stack **b)
{
	char	*instruction;

	instruction = get_next_line(0);
	while (instruction)
	{
		execute_and_cmp(a, b, instruction);
		free(instruction);
		instruction = get_next_line(0);
	}
	return (0);
}

int	string_arg_to_list(t_stack *a, t_stack *b, char **av)
{
	b = NULL;
	a = single_arg(av[1]);
	if ((!av) || !a || (*av[1] == 0) || check_duplicate(a, b) == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (check_output(&a, &b) == 0)
	{
		if (check_sort(a, b) == 1 && b == NULL)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	else
		write(2, "Error\n", 6);
	free_lsts(&a, &b);
	return (0);
}

int	mult_arg_to_list(t_stack *a, t_stack *b, int ac, char **av)
{
	b = NULL;
	a = argv_list(ac, av);
	if (check_duplicate(a, b) == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	check_output(&a, &b);
	if (check_sort(a, b) == 1 && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_lsts(&a, &b);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac > 1)
	{
		if (ac == 2 && check_argv_overflow(av[1]) == 0)
			string_arg_to_list(stack_a, stack_b, av);
		else if (ac > 2 && check_argc_overflow(ac, av) == 0)
			mult_arg_to_list(stack_a, stack_b, ac, av);
		else
			write(2, "Error\n", 6);
	}
	return (0);
}
