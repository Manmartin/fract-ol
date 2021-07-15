NAME = fractol 
CFLAGS	= -Wall -Wextra -Werror
SRC	 = fractol.c \
	graphics/render.c graphics/window_manager.c \
	fractals/mandelbrot.c fractals/julia.c fractals/ship.c\
	complex/complex_functions.c 
OBJS = $(SRC:.c=.o)
HEADERS = fractol.h complex/complx.h graphics/macros.h

CC = gcc
MLX	= ./mlx/
EXTRA_FLAGS = -LMLX -lmlx -framework OpenGL -framework AppKit -lm

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(EXTRA_FLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

norm:
	norminette $(SRC) $(HEADERS)

re: fclean all

.PHONY: all clean fclean re
