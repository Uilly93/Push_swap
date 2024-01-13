# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 13:19:14 by wnocchi           #+#    #+#              #
#    Updated: 2023/11/29 10:00:35 by wnocchi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
SRCS = ft_printf.c ft_is_c.c ft_is_di.c ft_is_p.c ft_is_s.c ft_is_u.c ft_is_xl.c ft_is_xu.c ft_mandatory.c ft_putchar.c ft_putnbr_base.c ft_putnbr_base_long.c ft_putnbr.c ft_putstr.c ft_strlen.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)
	
$(NAME): $(OBJS)
	ar r $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
	
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re