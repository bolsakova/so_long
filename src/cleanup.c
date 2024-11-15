/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:40:12 by tbolsako          #+#    #+#             */
/*   Updated: 2024/11/14 14:25:00 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_array_1(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_array(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	exit(EXIT_FAILURE);
}

void	clean_textures(t_game *game)
{
	mlx_delete_texture(game->t_exit);
	mlx_delete_texture(game->t_player);
	mlx_delete_texture(game->t_wall);
	mlx_delete_texture(game->t_empty);
	mlx_delete_texture(game->t_collectibles);
}

void	cleanup(t_game *game, t_render *render)
{
	int	i;

	i = 0;
	while (game->map_data && game->map_data[i])
	{
		free(game->map_data[i]);
		i++;
	}
	free(game->map_data);
	mlx_delete_image(render->mlx, game->img_player);
	mlx_delete_image(render->mlx, game->img_wall);
	mlx_delete_image(render->mlx, game->img_collectibles);
	mlx_delete_image(render->mlx, game->img_exit);
	mlx_delete_image(render->mlx, game->img_empty);
	clean_textures(game);
}
