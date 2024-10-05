/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:22:58 by tbolsako          #+#    #+#             */
/*   Updated: 2024/10/05 16:36:04 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "./printf/ft_printf.h"
# include "MLX42/include/MLX42/MLX42.h"
// file control options library
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 1024
// define the size of each tile in pixels
# define TILE_SIZE 32
// the player's starting position
# define PLAYER 'P'
// a map exit
# define EXIT 'E'
// collectible items
# define COLLECTIBLE 'C'
// walls
# define WALL '1'
// an empty space
# define EMPTY '0'

// game's structure
typedef struct s_game
{
	char	**map_data;
	int		map_length;
	int		map_height;
	int		player_pos_x;
	int		player_pos_y;
	int		collectibles;
	int		collected;
	int		game_over;
	int		steps;
	void	*img_player;
	void	*img_wall;
	void	*img_collectibles;
	void	*img_exit;
	void	*img_empty;
}			t_game;

typedef struct s_render
{
	void	*mlx;
	void	*win;
}			t_render;

#endif
