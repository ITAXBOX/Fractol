NAME        = fractol
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -Ofast -march=native -flto -funroll-loops -ffast-math
MLX_DIR     = minilibx-linux
PRINTF_DIR  = printf

SRC         = main.c fractals/mandelbrot.c fractals/julia.c fractals/drawer.c fractals/burning_ship.c tools/window.c tools/utils.c tools/math.c tools/render_tools.c tools/hooks.c
OBJ         = $(SRC:.c=.o)

MLX_LIB     = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
PRINTF_LIB  = -L$(PRINTF_DIR) -lftprintf

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX_LIB) $(PRINTF_LIB)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -I$(PRINTF_DIR) -I. -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(PRINTF_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re