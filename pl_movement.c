/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:04:08 by tbolsako          #+#    #+#             */
/*   Updated: 2024/11/08 21:10:56 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// function to handle player movement
void	move_player(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_y < 0 || new_x >= game->map_length
		|| new_y >= game->map_height)
		return ; // Prevent moving out of bounds
	if (game->map_data[new_y][new_x] == EXIT)
		game->game_over = 1; // set game over flag
	// check if the new pos is within bounds and not a wall
	if (game->map_data[new_y][new_x] != WALL)
	{
		// check if the new pos is a collectible
		if (game->map_data[new_y][new_x] == COLLECTIBLE)
		{
			game->collectibles--; // decrease the collectible count
			game->collected++;    // increase the collected count
			game->map_data[new_y][new_x] = EMPTY;
		}
		// update player's pos
		game->player_pos_x = new_x;
		game->player_pos_y = new_y;
		game->steps++;
	}
}

// function to handle key presses
void	handle_keypress(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	// check for ESC key to exit the game
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->render->mlx);
	// handle other key presses for player movement
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_W)
			move_player(game, game->player_pos_x, game->player_pos_y - 1);
		else if (keydata.key == MLX_KEY_S)
			move_player(game, game->player_pos_x, game->player_pos_y + 1);
		else if (keydata.key == MLX_KEY_A)
			move_player(game, game->player_pos_x - 1, game->player_pos_y);
		else if (keydata.key == MLX_KEY_D)
			move_player(game, game->player_pos_x + 1, game->player_pos_y);
	}
	render_game(game, game->render);
}
