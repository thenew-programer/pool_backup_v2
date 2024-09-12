CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./$(INCLUDE_DIR)
ARFLAGS = -rcs

SRCS_DIR = srcs
INCLUDE_FILE = includes/ft.h

SRCS = $(SRCS_DIR)/ft_putchar.c $(SRCS_DIR)/ft_swap.c $(SRCS_DIR)/ft_putstr.c $(SRCS_DIR)/ft_strlen.c $(SRCS_DIR)/ft_strcmp.c
OBJS = $(SRCS:.c=.o)

TARGET = libft.a

all:$(TARGET)

$(TARGET):$(OBJS)
	ar $(ARFLAGS) $@ $^

%.o:$(SRCS)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(SRCS_DIR)/*.o

fclean: clean
	rm -f *.a

re: fclean all

.PHONY: all re clean fclean
