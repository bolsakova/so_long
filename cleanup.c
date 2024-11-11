/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryusupov <ryusupov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:40:12 by tbolsako          #+#    #+#             */
/*   Updated: 2024/11/11 14:25:01 by ryusupov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_textures(t_game *game)
{
	mlx_delete_texture(game->t_exit);
	mlx_delete_texture(game->t_player);
	mlx_delete_texture(game->t_wall);
	mlx_delete_texture(game->t_empty);
	mlx_delete_texture(game->t_collectibles);
}

// cleanup function to free resources when the game ends
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
