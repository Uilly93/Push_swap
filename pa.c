/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 20:13:56 by wnocchi           #+#    #+#             */
/*   Updated: 2023/12/29 21:52:05 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pa(int *sa, int *sb)
{
	int tmp;
	int stash;
	int i;

	i = 0;
	if (sb[0] == '\0')
		return (0);
	tmp = sa[0];
	stash = sb[0];
	while (sa[i])
	{
		i++;
		sa[i] = stash;
		stash = sa[i + 1];
	}
	return (1);
}
