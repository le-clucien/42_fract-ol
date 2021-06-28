# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clucien <clucien@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/27 12:13:59 by clucien           #+#    #+#              #
#    Updated: 2020/06/18 12:23:44 by clucien          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fract-ol

FILES_C		=	\
				main.c \
				routers.c \
				window.c

DIR_C		=	srcs/

SRCS		=	$(addprefix $(DIR_C), $(FILES_C))

OBJS		=	$(SRCS:.c=.o)

LIBFT		=	libft/libft.a

CC			=	gcc -Wall -Wextra -Werror

MLX_FLG		=	-LminilibX -lmlx -L/usr/include/../lib -lXext -lX11 -lm -lbsd

.SILENT		:

$(NAME)		:	lib mandatory

all			:	$(NAME)

lib			:
		cd libft ; make ; cd .. 

print_s		:
		echo -n "srcs: "
printv_s	: 
		echo " ✓"

.c.o		:
		echo -n "#"
		$(CC) -c $< -o $(<:.c=.o)

mandatory	: print_s $(OBJS) printv_s
	$(CC) -o $(NAME) $(OBJS) $(LIBFT) $(MLX_FLG)

clean		:
		rm -f $(OBJS)
		cd libft ; make clean ; cd ..
		echo "Clean ✓"

fclean		:	clean
		rm -f $(NAME)
		cd libft ; make fclean ; cd ..
		rm -rf *.dSYM
		rm -rf *.vscode

aclean		:	all clean

re			:	fclean all

.PHONY		:	all clean fclean aclean re
