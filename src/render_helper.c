/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 07:43:05 by tbolsako          #+#    #+#             */
/*   Updated: 2024/11/12 08:45:28 by tbolsako         ###   ########.fr       */
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

	x *= 50;
	y *= 50;
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
