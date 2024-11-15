/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 19:48:50 by tbolsako          #+#    #+#             */
/*   Updated: 2024/11/14 14:39:07 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_tile(t_game *game, t_render *render, int x, int y)
{
	char		tile;
	mlx_image_t	*img;

	(void)render;
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
		img_to_img(game->img_mlx, img, x, y);
}

void	render_player(t_game *game, t_render *render)
{
	(void)render;
	img_to_img(game->img_mlx, game->img_player, game->player_pos_x,
		game->player_pos_y);
}

void	render_map(t_game *game, t_render *render)
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

void	render_game(void *param)
{
	t_game	*game;

	game = param;
	if (game->img_str)
	{
		mlx_delete_image(game->render->mlx, game->img_str);
		game->img_str = NULL;
	}
	render_map(game, game->render);
	render_player(game, game->render);
	game->img_str = mlx_put_string(game->render->mlx, ft_itoa(game->steps), 10,
			10);
}
