/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:31:46 by tbolsako          #+#    #+#             */
/*   Updated: 2024/11/08 16:06:38 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_loop(void *param)
{
	t_game	*game;

	game = (t_game *)param;          // Cast the parameter to t_game
	render_game(game, game->render); // Render the game state
}
