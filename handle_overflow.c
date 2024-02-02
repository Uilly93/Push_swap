/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_overflow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:18:31 by wnocchi           #+#    #+#             */
/*   Updated: 2024/02/02 12:22:09 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	overflow_cmp(long sign, long nb)
{
	if (nb * sign > INT_MAX)
		return (1);
	else if (nb * sign < INT_MIN)
		return (1);
	return (0);
}

int	overflow_skip(char *s, int i)
{
	if (s[i] == '-' && !(s[i + 1] >= '0' && s[i + 1] <= '9'))
		return (1);
	if (s[i] == '+' && !(s[i + 1] >= '0' && s[i + 1] <= '9'))
		return (1);
	return (0);
}

int	checker_atoi_overflow(char *s, int *i2)
{
	int		i;
	long	nb;
	long	sign;

	i = *i2;
	sign = 1;
	nb = 0;
	while ((s[i] >= 9 && s[i] <= 13) || (s[i] == 32))
		i++;
	if (s[i] == '+' && (s[i + 1] >= '0' && s[i + 1] <= '9'))
		i++;
	if (overflow_skip(s, i))
		return (1);
	if (s[i] == '-')
		sign *= -1 + (0 * i++);
	while (s[i] >= '0' && s[i] <= '9')
	{
		nb = nb * 10 + (s[i] - '0');
		if (overflow_cmp(sign, nb) == 1)
			return (1);
		i++;
	}
	if (s[i] != '\0' && s[i] != ' ')
		return (1);
	return (*i2 = i, 0);
}

int	check_argc_overflow(int ac, char **av)
{
	int	i;
	int	i2;

	i = 1;
	while (i < ac)
	{
		i2 = 0;
		if (checker_atoi_overflow(av[i], &i2) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	check_argv_overflow(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (checker_atoi_overflow(av, &i) == 1)
			return (1);
	}
	return (0);
}
