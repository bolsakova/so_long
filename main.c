/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:30:36 by tbolsako          #+#    #+#             */
/*   Updated: 2024/11/11 22:27:04 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_array(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	exit(EXIT_FAILURE);
}

static void	check_args(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("Error: Invalid number of arg\n");
		exit(EXIT_FAILURE);
	}
	if (!ft_strnstr(av[1], ".ber", ft_strlen(av[1])))
	{
		ft_printf("Error: Invalid file extension\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int ac, char *av[])
{
	t_game		game;
	t_render	render;

	check_args(ac, av);
	if (!init_game(&game, &render, av[1]))
	{
		ft_printf("Error: Failed to initialize the game\n");
		free_array(game.map_data);
	}
	load_textures(&game);
	render_textures(&game, &render);
	game.img_str = NULL;
	mlx_loop_hook(render.mlx, render_game, &game);
	mlx_key_hook(render.mlx, handle_keypress, &game);
	mlx_loop(render.mlx);
	cleanup(&game, &render);
	mlx_terminate(render.mlx);
	return (EXIT_SUCCESS);
}
