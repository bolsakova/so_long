/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 08:30:30 by tbolsako          #+#    #+#             */
/*   Updated: 2024/11/14 14:48:15 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	prepare_map_to_fill(t_game *str)
{
	int	y;
	int	i;

	i = 0;
	if (str->fill == NULL)
	{
		y = str->map_height;
		str->fill = (char **)malloc(sizeof(char *) * (y + 1));
		if (!str->fill)
			exit(-1);
		while (i < str->map_height)
		{
			str->fill[i] = (char *)ft_calloc(str->map_length + 1, sizeof(char));
			if (!str->fill[i])
				exit(-1);
			ft_strlcpy(str->fill[i], str->map_data[i], str->map_length + 1);
			i++;
		}
		str->fill[i] = NULL;
	}
}

void	flood_fill(t_game *map, int x, int y, char c)
{
	if (x < 0 || x >= map->map_length || y < 0 || y >= map->map_height)
		return ;
	if (map->fill[y][x] == c || map->fill[y][x] == '1')
		return ;
	map->fill[y][x] = c;
	flood_fill(map, x - 1, y, c);
	flood_fill(map, x + 1, y, c);
	flood_fill(map, x, y - 1, c);
	flood_fill(map, x, y + 1, c);
}

void	find_not_filled_target(t_game *map, int width, int height)
{
	int	y;
	int	x;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (map->fill[y][x] != '1' && map->fill[y][x] != 'X')
			{
				ft_printf("Error\nInvalid path!\n");
				free_array(map->fill);
				exit(EXIT_FAILURE);
			}
			x++;
		}
		y++;
	}
	free_array_1(map->fill);
}
