/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 19:48:50 by tbolsako          #+#    #+#             */
/*   Updated: 2024/11/11 22:34:36 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	pixel(mlx_image_t *img, uint32_t x, uint32_t y)
{
	int		r;
	int		g;
	int		b;
	int		a;
	uint8_t	*pixel;

	if (x > img->width || y > img->height)
		return (0xFF000000);
	pixel = img->pixels + (y * img->width + x) * sizeof(uint32_t);
	r = pixel[0];
	g = pixel[1];
	b = pixel[2];
	a = pixel[3];
	if (a == 0)
		return (-1);
	return (r << 24 | g << 16 | b << 8 | a);
}

void	img_to_img(mlx_image_t *dst, mlx_image_t *src, int x, int y)
{
	uint32_t	i;
	uint32_t	j;
	int			color;

	x *= 32;
	y *= 32;
	i = 0;
	while (i < src->height)
	{
		j = 0;
		while (j < src->width)
		{
			color = pixel(src, j, i);
			if (color != -1)
				mlx_put_pixel(dst, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

// function to render a single tile based on its type
void	render_tile(t_game *game, t_render *render, int x, int y)
{
	char		tile;
	mlx_image_t	*img;

	(void)render;
	img = NULL;
	tile = game->map_data[y][x];
	if (tile == WALL)
		img = game->img_wall;
	else if (tile == COLLECTIBLE)
		img = game->img_collectibles;
	else if (tile == EXIT)
		img = game->img_exit;
	else if (tile == EMPTY || tile == PLAYER)
		img = game->img_empty;
	if (img)
		img_to_img(game->img_mlx, img, x, y);
	// mlx_image_to_window(render->mlx, img, x * TILE_SIZE, y * TILE_SIZE);
}

// function to render the player at their current pos
void	render_player(t_game *game, t_render *render)
{
	(void)render;
	img_to_img(game->img_mlx, game->img_player, game->player_pos_x,
		game->player_pos_y);
	// mlx_image_to_window(render->mlx, game->img_player, game->player_pos_x
	// 	* TILE_SIZE, game->player_pos_y * TILE_SIZE);
}

// function to render the entire map
void	render_map(t_game *game, t_render *render)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_length)
		{
			render_tile(game, render, x, y);
			x++;
		}
		y++;
	}
}

// main rendering function

void	render_game(void *param)
{
	t_game	*game;

	game = param;
	if (game->img_str)
	{
		mlx_delete_image(game->render->mlx, game->img_str);
		game->img_str = NULL;
	}
	render_map(game, game->render);
	render_player(game, game->render);
	game->img_str = mlx_put_string(game->render->mlx, ft_itoa(game->steps), 10,
			10);
}
