/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 20:03:18 by wnocchi           #+#    #+#             */
/*   Updated: 2024/01/15 10:48:31 by wnocchi          ###   ########.fr       */
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

#endif