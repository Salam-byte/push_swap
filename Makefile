NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = main.c ft_split.c error.c free.c find_high_and_last.c my_sorting_algorthim.c my_sorting_algorthim2.c my_sorting_algorthim3.c push_node.c rotate.c reverse_rotate.c smallest_sort.c stack_init.c swap.c

OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
