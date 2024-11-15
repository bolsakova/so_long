/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 08:30:30 by tbolsako          #+#    #+#             */
/*   Updated: 2024/11/15 16:43:00 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	prepare_map_to_fill(t_game *game)
{
	int	y;
	int	i;

	i = 0;
	if (game->fill == NULL)
	{
		y = game->map_height;
		game->fill = (char **)malloc(sizeof(char *) * (y + 1));
		if (!game->fill)
			exit(-1);
		while (i < game->map_height)
		{
			game->fill[i] = (char *)ft_calloc(game->map_length + 1,
					sizeof(char));
			if (!game->fill[i])
				exit(-1);
			ft_strlcpy(game->fill[i], game->map_data[i], game->map_length + 1);
			i++;
		}
		game->fill[i] = NULL;
	}
}

void	flood_fill(t_game *game, int x, int y, char c)
{
	if (x < 0 || x >= game->map_length || y < 0 || y >= game->map_height)
		return ;
	if (game->fill[y][x] == c || game->fill[y][x] == '1')
		return ;
	game->fill[y][x] = c;
	flood_fill(game, x - 1, y, c);
	flood_fill(game, x + 1, y, c);
	flood_fill(game, x, y - 1, c);
	flood_fill(game, x, y + 1, c);
}

void	find_not_filled_target(t_game *game, int width, int height)
{
	int	y;
	int	x;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (game->fill[y][x] != '1' && game->fill[y][x] != 'X')
			{
				ft_printf("Error\nInvalid path!\n");
				free_array(game->fill);
				exit(EXIT_FAILURE);
			}
			x++;
		}
		y++;
	}
	free_array_1(game->fill);
}
