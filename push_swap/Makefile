NAME = pushswap
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3 -I ./libft
SRC =			main.c\
				parse.c\
				moves.c\
				sort.c\
				set_stack.c

OBJECTS = $(SRC:.c=.o)
LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

clean:
	rm -rf $(OBJECTS)
	make clean -C libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
