# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnuno-da <jnuno-da@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/25 23:23:36 by jnuno-da          #+#    #+#              #
#    Updated: 2025/03/07 00:22:59 by jnuno-da         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables
NAME = libft.a

CFLAGS = -Wall -Werror -Wextra
CC = cc

SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_striteri.c \
		ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
		ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \

BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
				ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
				ft_lstmap.c \

OBJ = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

AR = ar rcs

RM = rm -f 

#Rules

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

bonus: $(OBJ) $(BONUS_OBJS)
	$(AR) $(NAME) $(OBJ) $(BONUS_OBJS)

clean:
	$(RM) $(OBJ) $(BONUS_OBJS)
	@echo "Objects deleted"

fclean:
	$(RM) $(OBJ) $(NAME) $(BONUS_OBJS)
	@echo "Libft deleted"

re: fclean all



