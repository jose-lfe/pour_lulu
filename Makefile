NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_PATH = ./library/libft
MLX_PATH = ./library/minilibx_opengl_20191021
LIBFT = -L$(LIBFT_PATH) -lft
MLX = -L$(MLX_PATH) -lmlx
FRAMEWORKS = -framework OpenGL -framework AppKit
LIBFT_SENTINEL = $(LIBFT_PATH)/libft_built.sentinel

SRCS = src/main.c src/map_check.c src/on_the_map.c 
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_SENTINEL)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(FRAMEWORKS) -lm -o $(NAME)

$(LIBFT_SENTINEL):
	make -C $(LIBFT_PATH) bonus
	touch $(LIBFT_SENTINEL)

$(OBJS): %.o : %.c
	$(CC) $(CFLAGS) -I$(LIBFT_PATH) -I$(MLX_PATH) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_SENTINEL) # Ajoutez cette ligne pour supprimer le sentinelle lors d'un fclean
	make -C $(LIBFT_PATH) fclean

re: fclean all
