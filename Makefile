# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/03 16:10:45 by tbolsako          #+#    #+#              #
#    Updated: 2024/11/08 21:04:36 by tbolsako         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC = main.c cleanup.c init_game.c map_parser.c map_parser_helper.c \
		pl_movement.c render.c utils.c
OBJECTS = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror
CC = cc

GET_NEXT_LINE_DIR = get_next_line
PRINTF_DIR = printf
LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a
GET_NEXT_LINE = $(GET_NEXT_LINE_DIR)/get_next_line.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

MLX = MLX42/build/libmlx42.a

all: $(NAME)

$(MLX):
	@git clone https://github.com/codam-coding-college/MLX42.git
	@cd MLX42 && cmake -B build && cmake --build build -j4

$(PRINTF):
	make -C $(PRINTF_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(GET_NEXT_LINE):
	make -C $(GET_NEXT_LINE_DIR)

$(NAME): $(MLX) $(OBJECTS) $(LIBFT) $(PRINTF) $(GET_NEXT_LINE)
	$(CC)  $(FLAGS) $(OBJECTS) $(LIBFT) $(PRINTF) $(GET_NEXT_LINE) $(MLX) -o $(NAME) -ldl -lglfw -lm -g

%.o: %.c so_long.h
	$(CC) $(FLAGS) -Imlx -c $< -o $@

clean:
	rm -rf $(OBJECTS)
	make clean -C $(PRINTF_DIR)
	make clean -C $(LIBFT_DIR)
	make clean -C $(GET_NEXT_LINE_DIR)
	rm -rf MLX42

fclean:	clean
	rm -rf $(NAME) $(MLX)
	make fclean -C $(PRINTF_DIR)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(GET_NEXT_LINE_DIR)

re: fclean all

.PHONY: all clean fclean re mlx