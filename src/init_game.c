/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 17:02:34 by tbolsako          #+#    #+#             */
/*   Updated: 2024/11/12 12:04:48 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_render(t_game *game, t_render *render)
{
	render->mlx = mlx_init(game->map_length * TILE_SIZE,
			game->map_height * TILE_SIZE, "so_long", true);
	if (!render->mlx)
		return (0);
	game->img_mlx = mlx_new_image(render->mlx, game->map_length * TILE_SIZE,
			game->map_height * TILE_SIZE);
	if (!game->img_mlx)
	{
		mlx_close_window(render->mlx);
		return (0);
	}
	mlx_image_to_window(render->mlx, game->img_mlx, 0, 0);
	return (1);
}

int	init_game(t_game *game, t_render *render, const char *map_file)
{
	ft_memset(game, 0, sizeof(t_game));
	game->render = render;
	if (!parse_map(game, map_file))
		return (0);
	if (!init_render(game, render))
		return (0);
	load_textures(game);
	render_textures(game, render);
	game->collected = 0;
	game->steps = 0;
	game->game_over = 0;
	return (1);
}
