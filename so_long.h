/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:22:58 by tbolsako          #+#    #+#             */
/*   Updated: 2024/11/11 06:52:07 by tbolsako         ###   ########.fr       */
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
# define TILE_SIZE 32

# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define WALL '1'
# define EMPTY '0'

// structure to hold rendering state
typedef struct s_render
{
	void			*mlx;
	void			*win;
}					t_render;

// structure to hold map validation counts
typedef struct s_map_check
{
	int				player_count;
	int				exit_count;
	int				collectibles;
}					t_map_check;

// structure to hold game state
typedef struct s_game
{
	char			**map_data;
	int				map_length;
	int				map_height;
	int				player_pos_x;
	int				player_pos_y;
	int				collectibles;
	int				collected;
	int				game_over;
	int				steps;
	mlx_texture_t	*t_exit;
	mlx_texture_t	*t_wall;
	mlx_texture_t	*t_player;
	mlx_texture_t	*t_empty;
	mlx_texture_t	*t_collectibles;
	mlx_image_t		*img_player;
	mlx_image_t		*img_wall;
	mlx_image_t		*img_collectibles;
	mlx_image_t		*img_exit;
	mlx_image_t		*img_empty;
	t_render		*render;
	mlx_t			*mlx;
	t_map_check		*check;
}					t_game;

// game initialization

int					init_game(t_game *game, t_render *render,
						const char *map_file);
int					init_render(t_game *game, t_render *render);

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
void				clean_textures(t_game *game);

// utils

mlx_image_t			*texture_to_image(t_game *game, char map_char);
void				load_textures(t_game *game);
void				render_textures(t_game *game, t_render *render);
int					flood_fill(t_game *game, int x, int y, char **visited);

#endif
