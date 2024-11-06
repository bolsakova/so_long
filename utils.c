/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 17:26:15 by tbolsako          #+#    #+#             */
/*   Updated: 2024/10/07 11:28:31 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	flood_fill(t_game *game, int x, int y, char **visited)
{
	if (x < 0 || y < 0 || x >= game->map_length || y >= game->map_height
		|| game->map_data[y][x] == WALL || visited[y][x])
		return (0);
	visited[y][x] = 1;
	if (game->map_data[y][x] == EXIT)
		return (1);
	return (flood_fill(game, x + 1, y, visited)
		|| flood_fill(game, x - 1, y, visited)
		|| flood_fill(game, x, y + 1, visited)
		|| flood_fill(game, x, y - 1, visited));
}
