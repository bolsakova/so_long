/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:56:31 by tbolsako          #+#    #+#             */
/*   Updated: 2024/11/14 14:38:47 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map_chars(t_game *game)
{
	int			i;
	t_map_check	check;

	i = 0;
	game->collectibles = 0;
	ft_memset(&check, 0, sizeof(t_map_check));
	while (i < game->map_height * game->map_length)
	{
		if (!check_char(game, game->map_data[i / game->map_length][i
				% game->map_length], i, &check))
			return (0);
		i++;
	}
	game->collectibles = check.collectibles_count;
	return (check.player_count == 1 && check.exit_count == 1
		&& check.collectibles_count > 0);
}

int	validate_map_structure(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		if (game->map_data[i][0] != WALL || game->map_data[i][game->map_length
			- 1] != WALL)
			return (0);
		i++;
	}
	return (check_horizontal_walls(game));
}

int	read_map_file(t_game *game, const char *filename)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!read_map_line(game, line, i))
		{
			free(line);
			close(fd);
			return (0);
		}
		free(line);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	game->map_height = i;
	return (1);
}

int	parse_map(t_game *game, const char *filename)
{
	char	c;

	c = 'X';
	game->map_data = (char **)malloc(MAX_MAP_HEIGHT * sizeof(char *));
	if (!game->map_data)
		return (0);
	game->map_height = 0;
	game->map_length = 0;
	if (!read_map_file(game, filename))
		return (0);
	return (validate_map_chars(game) && validate_map_structure(game));
}
