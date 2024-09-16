CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror -I ${HEAD}
RM			= rm -f

HEAD		= ./includes/
SRCS_DIR	= ./srcs
SRCS		= ${SRCS_DIR}/main.c ${SRCS_DIR}/util.c ${SRCS_DIR}/fileIO.c
OBJS		= ${SRCS:.c=.o}

NAME		= ft_display_file


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
