/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 20:03:18 by wnocchi           #+#    #+#             */
/*   Updated: 2024/01/25 13:53:27 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
#include "ft_printf/ft_printf.h"

typedef struct s_stack
{
	int 			content;
	struct s_stack	*next;
}					t_stack;

# include <stddef.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <threads.h>


void	ft_sa(t_stack **sa); //
void	ft_sb(t_stack **sb);
void	ft_ss(t_stack **sa, t_stack **sb);
void	ft_pa(t_stack **sa, t_stack **sb);
void	ft_pb(t_stack **sb, t_stack **sa);
void 	ft_ra(t_stack **sa);
void	ft_rb(t_stack **sb);
void	ft_rr(t_stack **sa, t_stack **sb);
void	ft_rra(t_stack **sa);
void	ft_rrb(t_stack **sb);
void	ft_rrr(t_stack **sa, t_stack **sb);

int		ft_atoi(char *s);// utils
int		ft_min(t_stack *s);
int		ft_max(t_stack *s);
int		find_pos(t_stack *s, int nb);
int		find_pos_b(t_stack *s, int nb);

void	place_it(t_stack **a, t_stack **b); // sort utils
void	place_it_b(t_stack **a, t_stack **b);
void	place_min(t_stack **s);
void	place_min_b(t_stack **s);
void	place_max_b(t_stack **s);

t_stack	*new_node(int nb); // list utils
int		lst_size(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *add);
int 	last_content(t_stack *s);

void	print_stack(t_stack **stack, char *name); // list manage
t_stack *single_arg(char *arg);
t_stack *argv_list(int ac, char **av);
int		handle_string_arg(t_stack *stack_a, t_stack *stack_b, char **av);
int		handle_multi_args(t_stack *stack_a, t_stack *stack_b, int ac, char **av);

int		display_error(void); // checks and errors
void	free_lsts(t_stack **a, t_stack **b);
int		check_duplicate(t_stack *a, t_stack *b);
int		global_checks(t_stack *a, t_stack *b);
int		check_sort(t_stack *a);

void	sort_two(t_stack **a);
void 	sort_three(t_stack **sa); // sort
void	algo_sort(t_stack **a, t_stack **b);
void	sort_four(t_stack **a, t_stack **b);
void	identify_size_check_sort(t_stack **a, t_stack **b);

void	determine_side_b(t_stack **b, int pos, int pos_b);
void	determine_side_a(t_stack **a, int pos, int pos_b);
int		find_optimal_move_for_b(t_stack *a, t_stack *b);

#endif