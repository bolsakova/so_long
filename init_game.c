/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 17:02:34 by tbolsako          #+#    #+#             */
/*   Updated: 2024/10/05 18:47:26 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	load_images(t_game *game, t_render *render)
{
	mlx_texture_t	*texture;

	texture = mlx_load_xpm42("...");
	game->img_player = mlx_texture_to_image(render->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_xpm42("...");
	game->img_wall = mlx_texture_to_image(render->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_xpm42("...");
	game->img_collectibles = mlx_texture_to_image(render->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_xpm42("...");
	game->img_exit = mlx_texture_to_image(render->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_xpm42("...");
	game->img_empty = mlx_texture_to_image(render->mlx, texture);
	mlx_delete_texture(texture);
	return (game->img_player && game->img_wall && game->img_collectibles
		&& game->img_exit && game->img_empty);
}

static int	init_render(t_game *game, t_render *render)
{
	render->mlx = mlx_init(game->map_length * TILE_SIZE, game->map_height
			* TILE_SIZE, "so_long", true);
	if (!render->mlx)
		return (0);
	if (!load_images(game, render))
	{
		mlx_terminate(render->mlx);
		return (0);
	}
	return (1);
}

int	init_game(t_game *game, t_render *render, const char *map_file)
{
	ft_memset(game, 0, sizeof(t_game));
	if (!parse_map(game, map_file))
	{
		ft_printf("Error: Invalid map\n");
		return (0);
	}
	if (!init_render(game, render))
	{
		ft_printf("Error: Failed to initialize renderer\n");
		return (0);
	}
	game->collected = 0;
	game->steps = 0;
	game->game_over = 0;
	return (1);
}
