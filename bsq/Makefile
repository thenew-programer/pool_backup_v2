CC = cc
CFLAGS = -Wall -Werror -Wextra -I ${HEAD}
RM = rm -f

SRCS_DIR = ./srcs
HEAD = ./includes/
SRCS = ${wildcard ${SRCS_DIR}/*.c}

NAME = bsq

all:	${NAME}

${NAME}: ${SRCS}
				${CC} ${CFLAGS} -o $@ $^

clean:
	${RM} ${OBJS}

fclean:
	${RM} ${NAME}

re: fclean all

.PHONY:	all clean fclean
