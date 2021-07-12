CFLAGS	= -Wall -Wextra -Werror
NAME = fractol 
SRC	 = fractol.c \
	graphics/render.c graphics/window_manager.c \
	fractals/mandelbrot.c fractals/julia.c\
	complex/complex_functions.c 
OBJS = $(SRC:.c=.o)

CC = gcc
MLX	= ./mlx/
EXTRA_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit -lm

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(EXTRA_FLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

norm:
	norminette $(SRC)

re: fclean all

.PHONY: all clean fclean re
