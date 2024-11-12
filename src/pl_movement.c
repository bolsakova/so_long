/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:04:08 by tbolsako          #+#    #+#             */
/*   Updated: 2024/11/12 12:03:54 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_y < 0 || new_x >= game->map_length
		|| new_y >= game->map_height)
		return ;
	if (game->map_data[new_y][new_x] != WALL)
	{
		if (game->map_data[new_y][new_x] == COLLECTIBLE)
		{
			game->collectibles--;
			game->collected++;
			game->map_data[new_y][new_x] = EMPTY;
		}
		game->player_pos_x = new_x;
		game->player_pos_y = new_y;
		game->steps++;
		ft_printf("%d\n", game->steps);
	}
	if (game->map_data[new_y][new_x] == EXIT)
	{
		if (game->collectibles == 0)
		{
			game->game_over = 1;
			mlx_close_window(game->render->mlx);
		}
	}
}

void	handle_keypress(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->render->mlx);
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			move_player(game, game->player_pos_x, game->player_pos_y - 1);
		else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			move_player(game, game->player_pos_x, game->player_pos_y + 1);
		else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
			move_player(game, game->player_pos_x - 1, game->player_pos_y);
		else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			move_player(game, game->player_pos_x + 1, game->player_pos_y);
	}
}
