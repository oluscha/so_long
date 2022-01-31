NAME = so_long

CC = gcc

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

FLAGS = -Wall -Wextra -Werror

LIBFT = -L libft/ -lft

HEADERS = so_long.h 

MLX = -L mlx

HEADERS = so_long.h 

SRC =	so_long.c	\
		read_check1.c \
		read_check2.c \
		press_F.c	\
		images_close.c \
		gnl/get_next_line.c	\
		gnl/get_next_line_utils.c					

OBJ = $(SRC:c=o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	make -C mlx
	make -C libft
	gcc $(FLAGS) $(MLX_FLAGS) -Imlx $(SRC) $(LIBFT) -I. -o $(NAME)

clean:
	make clean -C mlx
	make clean -C libft
	rm -f ${OBJ}

fclean: clean
		rm -f ${NAME}
		

re: fclean all

.PHONY: all clean fclean re