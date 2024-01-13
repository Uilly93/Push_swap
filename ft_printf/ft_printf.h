/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:40:32 by wnocchi           #+#    #+#             */
/*   Updated: 2023/11/28 14:28:06 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stddef.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>

int		ft_is_c(char c);
int		ft_is_di(int nb);
int		ft_is_p(void *ptr);
int		ft_is_s(const char *s);
int		ft_is_u(unsigned int nb);
int		ft_is_xl(int hexa);
int		ft_is_xu(int hexa);
int		ft_mandatory(const char *fmt, va_list args);
int		ft_printf(const char *s, ...);
int		ft_putchar(char c);
int		ft_putnbr_base(unsigned int nb, char *base);
int		ft_putnbr(long int nb);
int		ft_putnbr_base_long(unsigned long nb, char *base);
int		ft_putstr(char *s);
size_t	ft_strlen(char *s);

#endif