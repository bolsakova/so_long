/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:04:08 by tbolsako          #+#    #+#             */
/*   Updated: 2024/11/08 14:27:15 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// function to handle player movement
void	move_player(t_game *game, int new_x, int new_y)
{
	// check if the new pos is within bounds and not a wall
	if (game->map_data[new_y][new_x] != WALL)
	{
		// check if the new pos is a collectible
		if (game->map_data[new_y][new_x] == COLLECTIBLE)
		{
			game->collectibles--; // decrease the collectible count
			game->collected++;    // increase the collected count
		}
		// update player's pos
		game->player_pos_x = new_x;
		game->player_pos_y = new_y;
		game->steps++;
	}
}

// function to handle key presses
int	handle_keypress(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	// check for esc key to exit the game
	if (keycode = KEY_ESC)
	{
		mlx_close_window(game->render->mlx);
		return (0);
	}
	// determine the new pos based on the key pressed
	new_x = game->player_pos_x;
	new_y = game->player_pos_y;
	if (keycode == KEY_UP)
		new_y--; // move up
	if (keycode == KEY_DOWN)
		new_y++; // move down
	if (keycode == KEY_LEFT)
		new_x--; // move left
	if (keycode == KEY_RIGHT)
		new_x++; // move right
	
	// move the player to the new pos
	move_player(game, new_x, new_y);
	return (0);
}
