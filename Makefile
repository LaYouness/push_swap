CC = cc
FLAGS = -Wall -Wextra -Werror
SRC = bmoves.c checker.c list_func.c main.c operations.c sort_func.c split.c utils.c
OBJ = ${SRC:.c=.o}
NAME = push_swap
LIBFT = libft/libft.a
LIBFT_D = libft/
all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_D)

$(NAME): $(OBJ) $(LIBFT) 
	$(CC) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $^ -o $@

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_D)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_D)


re: fclean all