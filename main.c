/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:30:36 by tbolsako          #+#    #+#             */
/*   Updated: 2024/10/05 17:00:27 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		exit(EXIT_FAILURE);
	}
	mlx_loop_hook(render.mlx, (void *)&game_loop, &game);
	mlx_loop(render.mlx);
	cleanup(&game, &render);
	return (EXIT_SUCCESS);
}
