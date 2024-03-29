# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/13 11:11:37 by wnocchi           #+#    #+#              #
#    Updated: 2024/02/02 15:16:30 by wnocchi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker
CC = cc
PATH_GNL = GNL/
PATH_PRINTF = ft_printf/
MAIN = main.c 
SRCS = handle_overflow.c optimization.c optimization_utils.c execute_moves.c list_utils.c list_manage_display.c checks_and_errors.c sort_utils.c utils.c sort.c pa.c pb.c ra.c rb.c rra.c rrb.c rr.c rrr.c sa.c sb.c ss.c
SRCS_BONUS = checker.c GNL/get_next_line.c GNL/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -f

all: printf $(NAME) 

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MAIN) -L$(PATH_PRINTF) -lftprintf

bonus: printf $(BONUS_NAME) $(NAME)
$(BONUS_NAME): $(OBJS_BONUS) $(OBJS)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(OBJS_BONUS) $(OBJS) -L$(PATH_PRINTF) -lftprintf

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	cd $(PATH_PRINTF) && make clean

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
	cd $(PATH_PRINTF) && make fclean

re: fclean all

printf:
	$(MAKE) -C $(PATH_PRINTF)

.PHONY: all bonus clean fclean re printf