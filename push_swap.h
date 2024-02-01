/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 20:03:18 by wnocchi           #+#    #+#             */
/*   Updated: 2024/02/01 15:25:40 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include "ft_printf/ft_printf.h"
# include "GNL/get_next_line.h"
# include <stddef.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}					t_stack;

void	ft_sa(t_stack **sa);
void	ft_sb(t_stack **sb);
void	ft_ss(t_stack **sa, t_stack **sb);
void	ft_pa(t_stack **sa, t_stack **sb);
void	ft_pb(t_stack **sb, t_stack **sa);
void	ft_ra(t_stack **sa);
void	ft_rb(t_stack **sb);
void	ft_rr(t_stack **sa, t_stack **sb);
void	ft_rra(t_stack **sa);
void	ft_rrb(t_stack **sb);
void	ft_rrr(t_stack **sa, t_stack **sb);

long	ft_atoi(char *s);// utils
int		ft_min(t_stack *s);
int		ft_max(t_stack *s);
int		find_pos(t_stack *s, int nb);
int		find_pos_b(t_stack *s, int nb);

void	place_it(t_stack **a, t_stack **b); // sort utils
void	place_min(t_stack **s);
void	place_max_b(t_stack **s);

t_stack	*new_node(int nb); // list utils
int		lst_size(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *add);
int		last_content(t_stack *s);

void	print_stack(t_stack **stack, char *name); // list manage
t_stack	*single_arg(char *arg);
t_stack	*argv_list(int ac, char **av);
int		handle_string_arg(t_stack *stack_a, t_stack *stack_b, char **av);
int		multi_args(t_stack *stack_a, t_stack *stack_b, int ac, char **av);

// checks and errors
void	free_lsts(t_stack **a, t_stack **b);
int		check_duplicate(t_stack *a, t_stack *b);
// int		check_overflow(int ac, char **arg);
int		overflow_cmp(long nb, long sign);
int		overflow_skip(char *s, int i);
int		checker_atoi_overflow(char *s, int *i2);
int		check_argc_overflow(int ac, char **av);
int		check_argv_overflow(char *av);

//checker.c
int		ft_strcmp(char *s1, char *s2);
int		check_sort(t_stack *a, t_stack *b);



void	sort_two(t_stack **a); // sort
void	sort_three(t_stack **sa);
void	algo_sort(t_stack **a, t_stack **b);
void	sort_four(t_stack **a, t_stack **b);
void	identify_size_check_sort(t_stack **a, t_stack **b);

void	determine_side_a(t_stack **a, int pos, int pos_b); // Oprtimization
void	cmp_execute_case(t_stack **a, t_stack **b);
int		worth_move(t_stack **a, t_stack **b);
int		find_index(t_stack *s, int nb);

int		how_many_ra_rb(t_stack **a, t_stack **b, int nb); // Optimization_utils
int		how_many_ra_rrb(t_stack **a, t_stack **b, int nb);
int		how_many_rra_rb(t_stack **a, t_stack **b, int nb);
int		how_many_rra_rrb(t_stack **a, t_stack **b, int nb);

int		execute_rra_rrb(t_stack **a, t_stack **b, int nb);
int		execute_ra_rb(t_stack **a, t_stack **b, int nb);
int		execute_ra_rrb(t_stack **a, t_stack **b, int nb);
int		execute_rra_rb(t_stack **a, t_stack **b, int nb);


#endif