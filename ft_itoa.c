/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:26:50 by wnocchi           #+#    #+#             */
/*   Updated: 2024/01/29 17:48:05 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(char *s)
{
	int		i;
	char	*res;

	res = malloc(ft_strlen(s) + 1);
	i = 0;
	while (res[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static size_t	malloc_count(int n)
{
	long int	count;
	long int	nbr;

	nbr = n;
	count = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		count++;
	}	
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count + 1);
}

static void	ft_swap(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	ft_rev_int_tab(char *tab)
{
	int	first;
	int	last;

	first = 0;
	last = 0;
	last = ft_strlen(tab) - 1;
	while (first < last)
	{
		if (tab[first] == '-')
			first++;
		ft_swap(&tab[first], &tab[last]);
		first++;
		last--;
	}
}

char	*ft_itoa(int n)
{
	long int	nb;
	char		*ptr;
	size_t		i;

	i = 0;
	nb = n;
	if (nb == 0)
		return (ft_strdup("0"));
	ptr = malloc(malloc_count(nb));
	if (!ptr)
		return (NULL);
	if (nb < 0)
	{
		nb *= -1;
		ptr[0] = '-';
		i++;
	}
	while (nb > 0)
	{
		ptr[i++] = (nb % 10) + 48;
		nb /= 10;
	}
	ptr[i] = '\0';
	ft_rev_int_tab(ptr);
	return (ptr);
}
