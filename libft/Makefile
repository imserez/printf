# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjuarez <sjuarez@student.42.barcelona>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/05 13:14:02 by sjuarez           #+#    #+#              #
#    Updated: 2025/10/24 20:30:53 by sjuarez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libft.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -f

SRC         = ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_striteri.c
OBJ         = $(SRC:.c=.o)

BONUS       = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
BONUS_OBJ   = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c libft.h Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(OBJ) $(BONUS_OBJ)
	ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)

.PHONY: all clean fclean re bonus

