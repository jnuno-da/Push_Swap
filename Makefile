# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnuno-da <jnuno-da@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/29 00:51:13 by jnuno-da          #+#    #+#              #
#    Updated: 2025/02/01 11:40:18 by jnuno-da         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

CFLAGS = -Wall -Werror -Wextra
CC = cc

LIBFT	= libft/libft.a

SRCS = c_args.c index_stack.c lst_utils.c main.c radix.c sorting.c	\
		utils.c stack_instructions.c stack_moves.c stack_moves2.c \

OBJ = $(SRCS:.c=.o)

RM = rm -f 

#Rules

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	cd libft && $(MAKE)

clean:
	$(RM) $(OBJ)
	@echo "Objects deleted"

fclean: clean
	cd libft && $(MAKE) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY = all clean fclean re
