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
				draw.c \
				hook.c \
				quit.c \
				iterate.c \
				main.c \
				parsing.c \
				routers.c \
				window.c

FILES_B		=	\
				draw.c \
				hook_bonus.c \
				quit.c \
				iterate.c \
				main_bonus.c \
				parsing.c \
				routers.c \
				window.c

DIR_C		=	srcs/

SRCS		=	$(addprefix $(DIR_C), $(FILES_C))
SRCS_B		=	$(addprefix $(DIR_C), $(FILES_B))

OBJS		=	$(SRCS:.c=.o)
OBJS_B		=	$(SRCS_B:.c=.o)

LIBFT		=	libft/libft.a

CC			=	gcc -Wall -Wextra -Werror

MLX_FLG		=	-LminilibX -lmlx -L/usr/include/../lib -lXext -lX11 -lm -lbsd

.SILENT		:

$(NAME)		:	minilib lib mandatory

all			:	$(NAME)

bonus		:	minilib lib bonus_part

lib			:
		cd libft ; make ; cd .. 

minilib		:
		cd minilibX ; ./configure ; cd ..

print_s		:
		echo -n "srcs: "
print_b		:
		echo -n "srcs bonuses: "
printv		: 
		echo " ✓"

.c.o		:
		echo -n "#"
		$(CC) -c $< -o $(<:.c=.o)

mandatory	: print_s $(OBJS) printv
	$(CC) -o $(NAME) $(OBJS) $(LIBFT) $(MLX_FLG)

bonus_part	: print_b $(OBJS_B) printv
	$(CC) -o $(NAME) $(OBJS_B) $(LIBFT) $(MLX_FLG)

clean		:
		rm -f $(OBJS)
		rm -f $(OBJS_B)
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
