/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 17:02:34 by tbolsako          #+#    #+#             */
/*   Updated: 2024/11/08 20:05:36 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// function to init the rendering context
int	init_render(t_game *game, t_render *render)
{
	render->mlx = mlx_init(game->map_length * TILE_SIZE, game->map_height
			* TILE_SIZE, "so_long", true);
	if (!render->mlx)
		return (0);
	return (1);
}

// function to initialize the game state
int	init_game(t_game *game, t_render *render, const char *map_file)
{
	ft_memset(game, 0, sizeof(t_game));
	game->render = render;
	// parse the map file and initialize the game state
	if (!parse_map(game, map_file))
	{
		ft_printf("Error: Invalid map\n");
		return (0);
	}
	// initialize the rendering context
	if (!init_render(game, render))
	{
		ft_printf("Error: Failed to initialize renderer\n");
		return (0); // return 0 if initialization fails
	}
	// set initial game state
	game->collected = 0; // init collected items count
	game->steps = 0;     // init steps count
	game->game_over = 0; // init game over flag
	return (1);          // return 1 if initialization is successful
}
