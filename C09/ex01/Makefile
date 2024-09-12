CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(HEADER_DIR)

SRCS_DIR = srcs
HEADER_DIR = includes

HEADER = $(HEADER_DIR)/ft.h
SRCS = $(SRCS_DIR)/ft_putchar.c $(SRCS_DIR)/ft_swap.c $(SRCS_DIR)/ft_putstr.c $(SRCS_DIR)/ft_strlen.c $(SRCS_DIR)/ft_strcmp.c
OBJS = $(SRCS:.c=.o)

TARGET = libft.a

all: $(TARGET)

$(TARGET): $(OBJS)
	ar rcsv $@ $^

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(TARGET)

re: fclean all

.PHONY: $(TARGET) all clean fclean re
