# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjuarez <sjuarez@student.42barcelona.      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/28 16:52:37 by sjuarez           #+#    #+#              #
#    Updated: 2025/10/28 16:58:26 by sjuarez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
SRC = ft_printf.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$NAME: $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c ft_printf.h Makefile
	$(CC) $(CFLGAS) -c < -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
