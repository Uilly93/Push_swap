/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:36:18 by wnocchi           #+#    #+#             */
/*   Updated: 2024/02/01 15:48:30 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	return_error_exit(t_stack **a, t_stack **b)
{
	write(2, "Error\n", 6);
	free_lsts(a, b);
	exit(1);
}


int	execute_and_cmp(t_stack **a, t_stack **b, char *instruction)
{
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
		return(return_error_exit(a, b), 1);
	return (0);
}

int	check_output(t_stack **a, t_stack **b)
{
	char *instruction;

	instruction = get_next_line(0);
	if (!instruction)
		return (1);
	while(instruction)
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
	if (check_sort(a, b) == 0)
		return (free_lsts(&a, &b), 0);
	if ((!av) || !a || (*av[1] == 0) || check_duplicate(a, b) == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (check_output(&a, &b) == 0)
	{
		if(check_sort(a, b) == 0)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	else
	{
		write(2, "Error\n", 6);
		free_lsts(&a, &b);
		return (1);
	}
	free_lsts(&a, &b);
	return (0);
}

int	mult_arg_to_list(t_stack *a, t_stack *b, int ac, char **av)
{
	b = NULL;
	a = argv_list(ac, av);
	if (check_sort(a, b) == 1)
		return (free_lsts(&a, &b), 0);
	if (check_duplicate(a, b) == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	check_output(&a, &b);
	if(check_sort(a, b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_lsts(&a, &b);
	return (0);
}

int	main(int ac, char **av)
{
	if(ac > 1)
	{
		t_stack	*stack_a;
		t_stack	*stack_b;

		stack_a = NULL;
		stack_b = NULL;
		if (ac == 2 && check_argv_overflow(av[1]) == 0)
			string_arg_to_list(stack_a, stack_b, av);
		else if (ac > 2 && check_argc_overflow(ac, av) == 0)
			mult_arg_to_list(stack_a, stack_b, ac, av);
		else
			write(2, "Error\n", 6);	
	}
	return (0);
}

