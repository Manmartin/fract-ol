OS	= $(shell uname)
FLAGS	= -Wall -Wextra -Werror

NAME = fract-ol

SRC	 = fract-ol.c

OBJS = $(SRC:.c=.o)

MLX_A = $(shell echo "$(MLX)mlx.a")

# Choose minilibX folder and compiler
ifeq ($(OS), Linux)
	CC = gcc
	MLX	= ./mlx_linux/
	EXTRA_FLAGS	= -L ./mlx_linux/ -l mlx -lXext -lX11 -lm 
else
	CC = clang
	MLX	= ./mlx/
	EXTRA_FLAGS= -L ./mlx/ -l mlx -framework OpenGL -framework AppKit
endif


all: $(MLX_A) $(NAME)

$(MLX_A):
	@$(MAKE) -C $(MLX) > trash
	@rm trash

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(FLAGS) $(EXTRA_FLAGS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
