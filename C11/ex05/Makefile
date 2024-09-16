# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/16 14:28:10 by ybouryal          #+#    #+#              #
#    Updated: 2024/09/16 15:26:22 by ybouryal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR	= ./srcs

SRCS		= ${wildcard ${SRCS_DIR}/*.c}

OBJS		= ${SRCS:.c=.o}

HEAD		= ./includes/

NAME		= do-op

RM			= rm -f

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
