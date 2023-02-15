# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mehyildi <mehyildi@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 19:54:33 by mehyildi          #+#    #+#              #
#    Updated: 2023/02/14 00:24:18 by mehyildi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c \
			ft_printf_utils.c

NAME	= libftprintf.a

OBJS	= $(SRCS:.c=.o)

FLAGS	= -Wall -Wextra -Werror

$(NAME):
		gcc $(FLAGS)   -c $(SRCS) -I   ./
		ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re