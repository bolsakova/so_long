/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 19:48:50 by tbolsako          #+#    #+#             */
/*   Updated: 2024/11/08 14:35:07 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// function to render a single tile based on its type
void	render_tile(t_game *game, t_render *render, int x, int y)
{
	mlx_image_t	*img; // pointer to the image to render
	char		tile;

	img = NULL;
	tile = game->map_data[y][x]; // get the tile character
	// determine which image to use based on the tile type
	if (tile == WALL)
		img = game->img_wall; // wall image
	else if (tile == COLLECTIBLE)
		img = game->img_collectibles; // collectible image
	else if (tile == EXIT)
		img = game->img_exit; // exit image
	else if (tile == EMPTY || tile == PLAYER) // empty space or player
		img = game->img_empty; // empty space image
	// render the image to the window if it's valid
	if (img)
		mlx_image_to_window(render->mlx, img, x * TILE_SIZE, y * TILE_SIZE);
}

// function to render the player at their current pos
void	render_player(t_game *game, t_render *render)
{
	mlx_image_to_window(render->mlx, game->img_player, game->player_pos_x
		* TILE_SIZE, game->player_pos_y * TILE_SIZE);
}

// function to render the entire map
void	render_map(t_game *game, t_render *render)
{
	int	x;
	int	y;

	// loop through each tile in the map
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_length)
		{
			render_tile(game, render, x, y); // render each tile
			x++;
		}
		y++;
	}
}

// main rendering function
void	render_game(t_game *game, t_render *render)
{
	mlx_clear_window(render->mlx); // clear the previous frame
	// mlx_delete_image(render->mlx, game->img_player);
	// game->img_player = mlx_new_image(render->mlx, TILE_SIZE, TILE_SIZE);
	render_map(game, render); // render the map
	render_player(game, render); // render the player
	// optionally, display the num of steps taken
	mlx_put_string(render->mlx, ft_itoa(game->steps), 10, 10);
}
