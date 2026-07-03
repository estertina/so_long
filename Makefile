# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/22 03:54:42 by esttina           #+#    #+#              #
#    Updated: 2026/06/28 08:44:45 by esttina          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(MLX_DIR) -Wno-deprecated-declarations

# OS DETECTION & MLX SETUP #
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	MLX_DIR = mlx_linux
	MLX_FLAGS = -L$(MLX_DIR) -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
else
	MLX_DIR = mlx_mac
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = main.c validate_map.c parse_map.c path_checker.c images.c render.c
OBJS = $(SRCS:.c=.o)

all: $(LIBFT) mlx $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

mlx:
	make -C $(MLX_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re mlx