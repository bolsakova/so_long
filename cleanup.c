/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:40:12 by tbolsako          #+#    #+#             */
/*   Updated: 2024/11/08 14:45:35 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// cleanup function to free resources when the game ends
void	cleanup(t_game *game, t_render *render)
{
	int	i;

	i = 0;
	// free the map data
	while (i < game->map_height)
	{
		free(game->map_data[i]); // free each row of the map
		i++;
	}
	free(game->map_data); // free the map data array itself
	// free images
	mlx_delete_image(render->mlx, game->img_player);
	mlx_delete_image(render->mlx, game->img_wall);
	mlx_delete_image(render->mlx, game->img_collectibles);
	mlx_delete_image(render->mlx, game->img_exit);
	mlx_delete_image(render->mlx, game->img_empty);
	// terminate MLX
	mlx_terminate(render->mlx);
}
