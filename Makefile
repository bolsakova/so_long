# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/03 16:10:45 by tbolsako          #+#    #+#              #
#    Updated: 2024/11/14 14:43:40 by tbolsako         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC = src/main.c src/cleanup.c src/init_game.c src/map_parser.c \
		src/map_parser_helper.c src/pl_movement.c src/render.c \
		src/render_helper.c src/utils.c src/flood_fill_helper.c 
OBJECTS = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror
CC = cc

GET_NEXT_LINE_DIR = lib/get_next_line
PRINTF_DIR = lib/printf
LIBFT_DIR = lib/libft

LIBFT = $(LIBFT_DIR)/libft.a
GET_NEXT_LINE = $(GET_NEXT_LINE_DIR)/get_next_line.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

#for macOS
MLX42FLAGS      := -lglfw -framework Cocoa -framework OpenGL -framework IOKit
#for Ubuntu:
# MLX42FLAGS        := -lglfw -ldl -lGL

MLX = MLX42/build/libmlx42.a

all: $(NAME)

$(MLX):
	@git clone https://github.com/codam-coding-college/MLX42.git MLX42 || true
	@cd MLX42 && cmake -B build && cmake --build build -j4

$(PRINTF):
	make -C $(PRINTF_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(GET_NEXT_LINE):
	make -C $(GET_NEXT_LINE_DIR)


$(NAME): $(MLX) $(OBJECTS) $(LIBFT) $(PRINTF) $(GET_NEXT_LINE)
	$(CC)  $(FLAGS) $(OBJECTS) $(LIBFT) $(PRINTF) $(GET_NEXT_LINE) $(MLX) -o $(NAME) -ldl -lglfw -lm -g

%.o: %.c includes/so_long.h
	$(CC) $(FLAGS) -Iincludes -IMLX42/include -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(GET_NEXT_LINE_DIR) -c $< -o $@

clean:
	rm -rf $(OBJECTS)
	make clean -C $(PRINTF_DIR)
	make clean -C $(LIBFT_DIR)
	make clean -C $(GET_NEXT_LINE_DIR)
	rm -rf MLX42

fclean:	clean
	rm -rf $(NAME)
	make fclean -C $(PRINTF_DIR)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(GET_NEXT_LINE_DIR)

re: fclean all

.PHONY: all clean fclean re mlx
