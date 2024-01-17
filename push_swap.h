/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 20:03:18 by wnocchi           #+#    #+#             */
/*   Updated: 2024/01/17 16:16:10 by wnocchi          ###   ########.fr       */
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

t_stack	*new_node(int nb);

void	ft_sa(t_stack **sa);
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
void	ft_sort(t_stack **sa, t_stack **sb);
int		ft_atoi(char *s);
void 	sort_three(t_stack **sa);
int		lst_size(t_stack *lst);
int		ft_min(t_stack *s);
int		ft_max(t_stack *s);
int		find_pos(t_stack *s, int nb);
void	place_it(t_stack **a, t_stack **b);
void	algo_sort(t_stack **a, t_stack **b);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *add);
int 	last_content(t_stack *s);
t_stack	*ft_lstnew(int content);
void	print_stack(t_stack **stack, char *name);



#endif