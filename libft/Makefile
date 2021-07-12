# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clucien <clucien@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/12 17:27:31 by clucien           #+#    #+#              #
#    Updated: 2021/07/12 17:28:00 by clucien          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS	= \
	ft_atoi.c \
	ft_is_str.c \
	ft_is.c \
	ft_math.c \
	ft_memset.c \
	ft_putnbr.c \
	ft_putstr.c \
	ft_ret.c \
	ft_strlen.c \
	ft_strcmp.c \
	ft_to.c

OBJS	= $(SRCS:.c=.o)

CC		= gcc -Wall -Werror -Wextra

.SILENT		:

all			: $(NAME)

print_l		:
	echo -n "libft: "
printv_l	:
	echo " ✓"

.c.o		:
	echo -n "#"
	$(CC) -c $<

$(NAME)		: print_l $(OBJS) printv_l
	ar rcs $(NAME) $(OBJS)

clean		:
	rm -rf $(OBJS)

fclean		: clean
	rm -rf $(NAME)

ac			: all clean

re			: fclean all

.PHONY	: all clean fclean ac re
