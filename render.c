/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 19:48:50 by tbolsako          #+#    #+#             */
/*   Updated: 2024/10/05 20:04:15 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_tile(t_game *game, t_render *render, int x, int y)
{
	mlx_image_t	*img;
	char		tile;

	img = NULL;
	tile = game->map_data[y][x];
	if (tile == WALL)
		img = game->img_wall;
	else if (tile == COLLECTIBLE)
		img = game->img_collectibles;
	else if (tile == EXIT)
		img = game->img_exit;
	else if (tile == EMPTY || tile == PLAYER)
		img = game->img_empty;
	if (img)
		mlx_image_to_window(render->mlx, img, x * TILE_SIZE, y * TILE_SIZE);
}

static void	render_player(t_game *game, t_render *render)
{
	mlx_image_to_window(render->mlx, game->img_player,
		game->player_pos_x * TILE_SIZE, game->player_pos_y * TILE_SIZE);
}

static void	render_map(t_game *game, t_render *render)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_length)
		{
			render_tile(game, render, x, y);
			x++;
		}
		y++;
	}
}

void	render_game(t_game *game, t_render *render)
{
	mlx_delete_image(render->mlx, game->img_player);
	game->img_player = mlx_new_image(render->mlx, TILE_SIZE, TILE_SIZE);
	render_map(game, render);
	render_player(game, render);
	mlx_put_string(render->mlx, ft_itoa(game->steps), 10, 10);
}
