/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 18:12:48 by tbolsako          #+#    #+#             */
/*   Updated: 2024/11/14 14:40:01 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_map_line(t_game *game, char *line, int i)
{
	int	line_length;

	if (i >= MAX_MAP_HEIGHT)
	{
		return (0);
	}
	line_length = ft_strlen(line);
	if (line[line_length - 1] == '\n')
		line[--line_length] = '\0';
	if (i == 0)
		game->map_length = line_length;
	else if (line_length != game->map_length)
		return (0);
	game->map_data[i] = ft_strdup(line);
	if (game->map_data[i] == NULL)
	{
		free(game->map_data[i]);
		return (0);
	}
	return (game->map_data[i] != NULL);
}

int	check_horizontal_walls(t_game *game)
{
	int	j;

	j = 0;
	while (j < game->map_length)
	{
		if (game->map_data[0][j] != WALL || game->map_data[game->map_height
			- 1][j] != WALL)
			return (0);
		j++;
	}
	return (1);
}

int	check_char(t_game *game, char c, int i, t_map_check *check)
{
	if (c == PLAYER)
	{
		check->player_count++;
		game->player_pos_x = i % game->map_length;
		game->player_pos_y = i / game->map_length;
	}
	else if (c == EXIT)
		check->exit_count++;
	else if (c == COLLECTIBLE)
		check->collectibles_count++;
	else if (c != WALL && c != EMPTY)
		return (0);
	return (1);
}
