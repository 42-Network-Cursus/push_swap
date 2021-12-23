# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwastche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/23 09:55:48 by cwastche          #+#    #+#              #
#    Updated: 2021/12/23 09:55:54 by cwastche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECK = checker

SRC =		src/utils.c src/args_check.c src/init_stack.c src/push_swap.c \
			operations/push.c operations/rev_rotate.c operations/rotate.c operations/swap.c \
			algorithm/sort.c
CHECK_SRC = src/args_check.c src/utils.c src/init_stack.c \
			operations/push.c operations/rev_rotate.c operations/rotate.c operations/swap.c \
			get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
			bonus/checker.c algorithm/sort.c\

OBJ =		${SRC:.c=.o}
CHECK_OBJ = ${CHECK_SRC:.c=.o}

CC =		gcc
CFLAGS =	-Wall -Wextra -Werror


all :		${NAME}

bonus :		${CHECK}

${NAME} :	${OBJ}
		${MAKE} -C ./libft
		${CC} ${CFLAGS} ${OBJ} ./libft/libft.a -o ${NAME}

${CHECK} : ${CHECK_OBJ}
		${MAKE} -C ./libft
		${CC} ${CFLAGS} ${CHECK_OBJ} ./libft/libft.a -o ${CHECK}

clean : 
		${MAKE} -C ./libft fclean
		rm -rf ${OBJ}
		rm -rf ${CHECK_OBJ}

fclean :	clean
		rm -rf ${NAME}
		rm -rf ${CHECK}

re :		fclean all

.PHONY:		all clean fclean re
