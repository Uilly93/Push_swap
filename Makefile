# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/13 11:11:37 by wnocchi           #+#    #+#              #
#    Updated: 2024/01/13 17:18:37 by wnocchi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
PATH_PRINTF = ft_printf/
SRCS = new_node.c new_list.c pa.c sort.c pb.c ra.c rb.c rra.c rrb.c rr.c rrr.c sa.c sb.c ss.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
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