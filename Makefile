# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adubeau <marvin@42quebec.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 15:33:27 by adubeau           #+#    #+#              #
#    Updated: 2021/12/15 16:07:31 by adubeau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	push_swap

SRCS		= 	srcs/ft_algos.c \
				srcs/ft_print.c \
				srcs/ft_atoi.c \
				srcs/ft_split.c \
				srcs/ft_index_utils.c \
				srcs/push_swap.c \
				srcs/ft_moves.c \

CC      =   gcc
FLAGS   =   -Wall -Wextra -Werror -c
RM      =   rm -f
INCS 	= 	./includes
OBJS    =   $(SRCS:.c=.o)
FLAGS   =   -Wall -Wextra -Werror -c

all: $(NAME)

$(NAME):
		$(CC) $(FLAGS) $(SRCS)
	   	$(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)
	
re: fclean all clean

.PHONY: all clean fclean re
