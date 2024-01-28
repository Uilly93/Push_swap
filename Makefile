# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/13 11:11:37 by wnocchi           #+#    #+#              #
#    Updated: 2024/01/28 22:36:27 by wnocchi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
PATH_PRINTF = ft_printf/
SRCS = main.c optimization.c optimization_utils.c execute_moves.c list_utils.c list_manage_display.c checks_and_errors.c sort_utils.c utils.c sort.c pa.c pb.c ra.c rb.c rra.c rrb.c rr.c rrr.c sa.c sb.c ss.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -f

all: printf $(NAME) 

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(PATH_PRINTF) -lftprintf

clean:
	$(RM) $(OBJS)
	cd $(PATH_PRINTF) && make clean

fclean: clean
	$(RM) $(NAME)
	cd $(PATH_PRINTF) && make fclean

re: fclean all

printf:
	$(MAKE) -C $(PATH_PRINTF)

.PHONY: all clean fclean re printf