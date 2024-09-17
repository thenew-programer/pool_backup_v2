CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror -I ${HEAD}
RM			= rm -f

HEAD		= ./includes/
SRCS_DIR	= ./srcs
SRCS		= ${wildcard $(SRCS_DIR)/*.c}
OBJS		= ${SRCS:.c=.o}

NAME		= ft_hexdump


.c.o:
				${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
				${CC} -o $@ $^



all:	${NAME}

clean:
				${RM} ${OBJS}

fclean:		clean
				${RM} ${NAME}

.PHONY:		all clean fclean
