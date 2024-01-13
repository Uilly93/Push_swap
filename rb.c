#include "push_swap.h"

void	ft_rb(t_stack **sb)
{
	t_stack	*current;
	int	tmp;

	current = *sb;

	while(current->next)
	{
		tmp = current->content;
		current->content = current->next->content;
		current->next->content = tmp;
		current = current->next;
	}
	ft_printf("rb");
}