# Project settings
NAME = so_long
CC = cc
# Tiny Note:
# -g flag is used to debug my project, without it debuggers will not
# get the debug information and I will not be able to debug my project.
# After finishing the project, just comment out this flag ;)
CFLAGS = -Wall -Wextra -I/usr/include -g -Imlx_linux -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz #-fsanitize=address -g
SRCS =	src/map_checkers.c \
		src/error.c		\
		src/game.c		\
		src/input.c		\
		src/main.c		\
		src/parser.c	\
		src/render.c	\
		src/utils.c		\

OBJS = $(SRCS:.c=.o)
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
MINILIBX_DIR = ./minilibx-linux
MINILIBX = $(MINILIBX_DIR)/libmlx.a

all: $(MINILIBX) $(LIBFT) $(NAME)

$(MINILIBX):
	$(MAKE) -C $(MINILIBX_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(MINILIBX) -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MINILIBX_DIR) clean
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re