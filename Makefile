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

SRCS = cost_chk.c error_utils.c f_swap.c main.c op_a_to_b.c p_back.c \
		push_utils_f.c reverse_utils_f.c rotate_utils_f.c stacks.c \

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
