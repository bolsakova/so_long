/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 17:26:15 by tbolsako          #+#    #+#             */
/*   Updated: 2024/11/14 14:35:12 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*texture_to_image(t_game *game, char map_char)
{
	if (map_char == EMPTY)
		return (game->img_empty);
	else if (map_char == WALL)
		return (game->img_wall);
	else if (map_char == EXIT)
		return (game->img_exit);
	else if (map_char == PLAYER)
		return (game->img_player);
	else if (map_char == COLLECTIBLE)
		return (game->img_collectibles);
	else
		return (NULL);
}

void	load_textures(t_game *game)
{
	game->t_exit = mlx_load_png("textures/exit.png");
	game->t_player = mlx_load_png("textures/player.png");
	game->t_collectibles = mlx_load_png("textures/collectible.png");
	game->t_wall = mlx_load_png("textures/wall.png");
	game->t_empty = mlx_load_png("textures/background.png");
}

void	render_textures(t_game *game, t_render *render)
{
	if (!game->img_exit)
		game->img_exit = mlx_texture_to_image(render->mlx, game->t_exit);
	if (!game->img_player)
		game->img_player = mlx_texture_to_image(render->mlx, game->t_player);
	if (!game->img_collectibles)
		game->img_collectibles = mlx_texture_to_image(render->mlx,
				game->t_collectibles);
	if (!game->img_wall)
		game->img_wall = mlx_texture_to_image(render->mlx, game->t_wall);
	if (!game->img_empty)
		game->img_empty = mlx_texture_to_image(render->mlx, game->t_empty);
}
