/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:15:32 by wnocchi           #+#    #+#             */
/*   Updated: 2024/01/13 16:08:09 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack **stack, char *name){
	ft_printf("this is %s stack\n", name);
	t_stack *current = *stack;
	while(current){
		ft_printf("%d -> ", current->content);
		current = current->next;
	}
	ft_printf("%p\n", current);
}


t_stack	*new_node(int nb)
{
	t_stack	*node;
	
	node = malloc(sizeof(t_stack));
	node->content = nb;
	node->next = NULL;
	return(node);
}
// t_stack **new_list(int ac, char **av)
// {
// 	int i;
	
// 	i = 1;
// 	while (i >= ac)
// 	{
// 		new_node(ft_atoi(av[i]));
// 		i++;
// 	}
// }

int main(int ac, char **av)
{
// Stack A :
	t_stack **sa;


// Stack B :
	t_stack **sb;



	ft_printf("before function\n");
	print_stack(sa, "sa");
	print_stack(sb, "sb");
	ft_sort(sa, sb); // Changer le nom de la fonction a tester
	// printf("after function\n");
	
	print_stack(sb, "sb");
	print_stack(sa, "sa");
	return 0;
}