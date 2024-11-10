/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:22:58 by tbolsako          #+#    #+#             */
/*   Updated: 2024/11/10 16:00:53 by tbolsako         ###   ########.fr       */
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

# define BUFFER_SIZE_ 1024
# define MAX_MAP_HEIGHT 100
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

// structure to hold rendering state
typedef struct s_render
{
	void *mlx; // pointer to the MLX instance
	void *win; // pointer to the game window
}					t_render;

// structure to hold map validation counts
typedef struct s_map_check
{
	int player_count; // count of players found in the map
	int exit_count;   // count of exits found in the map
	int collectibles; // count of collectibles found in the map
}					t_map_check;

// structure to hold game state
typedef struct s_game
{
	char **map_data;  // 2D array for the map data
	int map_length;   // length of the map (num of columns)
	int map_height;   // height of the map (num of rows)
	int player_pos_x; // player's x pos on the map
	int player_pos_y; // player's y pos on the map
	int collectibles; // total num of collectibles on the map
	int collected;    // num of collectibles collected by the player
	int game_over;    // flag to indicate if the game is over
	int steps;        // num of steps taken by the player
	mlx_texture_t	*t_exit;
	mlx_texture_t	*t_wall;
	mlx_texture_t	*t_player;
	mlx_texture_t	*t_empty;
	mlx_texture_t	*t_collectibles;
	mlx_image_t *img_player;       // pointer to the player's image
	mlx_image_t *img_wall;         // pointer to the wall's image
	mlx_image_t *img_collectibles; // pointer to the collectible's image
	mlx_image_t *img_exit;         // pointer to the exit's image
	mlx_image_t *img_empty;        // pointer to the empty space's image
	t_render *render;              // pointer to the rendering context
	mlx_t			*mlx;
	t_map_check		*check;
}					t_game;

// main

// map parser

int					parse_map(t_game *game, const char *filename);
int					read_map_file(t_game *game, const char *filename);
int					validate_path(t_game *game);
int					validate_map_structure(t_game *game);
int					validate_map_chars(t_game *game);

// map parser helper

int					read_map_line(t_game *game, char *line, int i);
int					allocate_visited(t_game *game, char ***visited);
int					check_horizontal_walls(t_game *game);
int					check_char(t_game *game, char c, int i, t_map_check *check);

// game initialization

int					init_game(t_game *game, t_render *render,
						const char *map_file);
int					init_render(t_game *game, t_render *render);

// game rendering

void				render_game(t_game *game, t_render *render);
void				render_map(t_game *game, t_render *render);
void				render_player(t_game *game, t_render *render);
void				render_tile(t_game *game, t_render *render, int x, int y);

// player movement

void				handle_keypress(mlx_key_data_t keydata, void *param);
void				move_player(t_game *game, int new_x, int new_y);

// cleanup

void				cleanup(t_game *game, t_render *render);

// utils

void				clean_textures(t_game *game);
mlx_image_t			*texture_to_image(t_game *game, char map_char);
void				load_textures(t_game *game);
void				render_textures(t_game *game, t_render *render);
int					flood_fill(t_game *game, int x, int y, char **visited);

#endif
