/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:21:48 by wnocchi           #+#    #+#             */
/*   Updated: 2023/12/29 21:52:46 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sa(int *sa)
{
	int tmp;
	
	if (!sa || sa[1] == '\0')
		return (0);
	tmp = sa[0];
	sa[0] = sa[1];
	sa[1] = tmp;
	return (1);
}

int main(void)
{
	int	sa[] = {1};
	int	i = 0;
	
	while(sa[i]){
		printf("%d ",sa[i]);
		i++;
	}
	printf("\n");
	ft_sa(sa);
	i = 0;
	while(sa[i]){
		printf("%d ",sa[i]);
		i++;
	}
}

