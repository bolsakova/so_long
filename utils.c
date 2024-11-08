/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 17:26:15 by tbolsako          #+#    #+#             */
/*   Updated: 2024/11/08 20:00:08 by tbolsako         ###   ########.fr       */
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
	game->t_exit = mlx_load_png("assets/exit.png");
	game->t_player = mlx_load_png("assets/player.png");
	game->t_collectibles = mlx_load_png("assets/collectible.png");
	game->t_wall = mlx_load_png("assets/wall.png");
	game->t_empty = mlx_load_png("assets/background.png");
}

void	render_textures(t_game *game, t_render *render)
{
	game->img_exit = mlx_texture_to_image(render->mlx, game->t_exit);
	game->img_player = mlx_texture_to_image(render->mlx, game->t_player);
	game->img_collectibles = mlx_texture_to_image(render->mlx,
			game->t_collectibles);
	game->img_wall = mlx_texture_to_image(render->mlx, game->t_wall);
	game->img_empty = mlx_texture_to_image(render->mlx, game->t_empty);
}

int	flood_fill(t_game *game, int x, int y, char **visited)
{
	if (x < 0 || y < 0 || x >= game->map_length || y >= game->map_height
		|| game->map_data[y][x] == WALL || visited[y][x])
		return (0);
	visited[y][x] = 1;
	if (game->map_data[y][x] == EXIT)
		return (1);
	return (flood_fill(game, x + 1, y, visited) || flood_fill(game, x - 1, y,
			visited) || flood_fill(game, x, y + 1, visited) || flood_fill(game,
			x, y - 1, visited));
}
