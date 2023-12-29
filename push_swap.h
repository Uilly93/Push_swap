/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 20:03:18 by wnocchi           #+#    #+#             */
/*   Updated: 2023/12/29 21:52:19 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <stddef.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int	ft_sa(int *sa);
int	ft_sb(int *sb);
int	ft_ss(int *sa, int *sb);
size_t	ft_strlen(int	*s);
int	ft_pa(int *sa, int *sb);


#endif