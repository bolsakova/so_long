/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:56:31 by tbolsako          #+#    #+#             */
/*   Updated: 2024/11/08 21:05:49 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// function to validate all characters in the map
int	validate_map_chars(t_game *game)
{
	int			i;
	t_map_check	check;

	i = 0;
	ft_memset(&check, 0, sizeof(t_map_check)); // initialize the check structure
	while (i < game->map_height * game->map_length)
	{
		// check each character in the map
		if (!check_char(game, game->map_data[i / game->map_length][i
				% game->map_length], i, &check))
			return (0); // return 0 if an invalid character is found
		i++;
	}
	game->collectibles = check.collectibles;
	// set the total collectibles in the game structure
	return (check.player_count == 1 && check.exit_count == 1
		&& check.collectibles > 0); // validate counts
}

// function to validate  the structure of the map
int	validate_map_structure(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		// check if the left and roght borders are walls
		if (game->map_data[i][0] != WALL || game->map_data[i][game->map_length
			- 1] != WALL)
			return (0); // return 0 if a wall is missing
		i++;
	}
	return (check_horizontal_walls(game)); // check horizontal walls
}

// function to validate if there is a valid path from the player to the exit
int	validate_path(t_game *game)
{
	int	result;
	int	i;

	char **visited; // array to track visited tiles
	i = 0;
	if (!allocate_visited(game, &visited))
		return (0);
	result = flood_fill(game, game->player_pos_x, game->player_pos_y, visited);
	// perform flood fill
	while (i < game->map_height)
		free(visited[i++]);
	free(visited);
	return (result); // return the result of the flood fill
}

// function to read the map file and populate the game structure
int	read_map_file(t_game *game, const char *filename)
{
	char *line; // variable to hold each line read from the file
	int fd;     // file descriptor
	int i;      // line index
	i = 0;
	fd = open(filename, O_RDONLY); // open the map file
	if (fd == -1)
		return (0);
	// return 0 if the file cannot be opened
	while ((line = get_next_line(fd)) != NULL) // read each line from the file
	{
		if (!read_map_line(game, line, i))
		// populate the game structure with the line
		{
			free(line);
			close(fd);
			return (0);
		}
		free(line);
		i++; // increment line index
	}
	close(fd);
	game->map_height = i; // set the height of the map
	return (1); // return 1 if reading is successful
}

// function to parse the map and validate its structure
int	parse_map(t_game *game, const char *filename)
{
	game->map_data = (char **)malloc(MAX_MAP_HEIGHT * sizeof(char *));
	if (!game->map_data) // check if memory allocation fails
		return (0);
	game->map_height = 0;               // initialize map height
	game->map_length = 0;               // initialize map length
	if (!read_map_file(game, filename)) // read the map file
		return (0);
	return (validate_map_chars(game) && validate_map_structure(game)
		&& validate_path(game)); // validate the map
}
