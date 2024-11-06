/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 17:02:34 by tbolsako          #+#    #+#             */
/*   Updated: 2024/11/06 14:08:19 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// function to load images for the game
static int	load_images(t_game *game, t_render *render)
{
	mlx_texture_t	*texture; // texture variable for loading images

	// load player image
	texture = mlx_load_png("assets/player.png");
	game->img_player = mlx_texture_to_image(render->mlx, texture);
	mlx_delete_texture(texture); // delete the texture after converting
	// load wall image
	texture = mlx_load_png("assets/wall.png");
	game->img_wall = mlx_texture_to_image(render->mlx, texture);
	mlx_delete_texture(texture);
	// load load collectible image
	texture = mlx_load_png("assets/collectible.png");
	game->img_collectibles = mlx_texture_to_image(render->mlx, texture);
	mlx_delete_texture(texture);
	// load exit image
	texture = mlx_load_png("assets/exit.png");
	game->img_exit = mlx_texture_to_image(render->mlx, texture);
	mlx_delete_texture(texture);
	// load empty space image
	texture = mlx_load_png("assets/empty.png");
	game->img_empty = mlx_texture_to_image(render->mlx, texture);
	mlx_delete_texture(texture);
	// return success if all images are loaded
	return (game->img_player && game->img_wall && game->img_collectibles
		&& game->img_exit && game->img_empty);
}

// function to init the rendering context
static int	init_render(t_game *game, t_render *render)
{
	// init the MLX window with the size based on the map dimensions
	render->mlx = mlx_init(game->map_length * TILE_SIZE, game->map_height
			* TILE_SIZE, "so_long", true);
	if (!render->mlx)
		return (0); // return 0 if init fails
	// load images for rendering
	if (!load_images(game, render))
	{
		mlx_terminate(render->mlx); // terminate MLX if loading fails
		return (0);
	}
	return (1); // return 1 if init is successful
}

// function to initialize the game state
int	init_game(t_game *game, t_render *render, const char *map_file)
{
	ft_memset(game, 0, sizeof(t_game)); // clear the game structure
	// parse the map file and initialize the game state
	if (!parse_map(game, map_file))
	{
		ft_printf("Error: Invalid map\n");
		return (0); // return 0 if parsing fails
	}
	// initialize the rendering context
	if (!init_render(game, render))
	{
		ft_printf("Error: Failed to initialize renderer\n");
		return (0); // return 0 if initialization fails
	}
	// set initial game state
	game->collected = 0; // init collected items count
	game->steps = 0; // init steps count
	game->game_over = 0; // init game over flag
	return (1); // return 1 if initialization is successful
}
