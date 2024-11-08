/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:30:36 by tbolsako          #+#    #+#             */
/*   Updated: 2024/11/08 16:05:15 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_args(int ac, char **av)
{
	// check if the num of args is correct
	if (ac != 2)
	{
		ft_printf("Error: Invalid number of arg\n");
		exit(EXIT_FAILURE); // exit the program eith failure status
	}
	// check if the provided file has a .ber extension
	if (!ft_strnstr(av[1], ".ber", ft_strlen(av[1])))
	{
		ft_printf("Error: Invalid file extension\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int ac, char *av[])
{
	t_game game;        // declare a game structure to hold game state
	t_render render;    // declare a render structure to hold rendering state
	check_args(ac, av); // validate command-line args
	// initialize the game with the provided map file
	if (!init_game(&game, &render, av[1]))
	{
		ft_printf("Error: Failed to initialize the game\n");
		exit(EXIT_FAILURE);
	}
	// set up the game loop to continuously render the game
	mlx_key_hook(render.mlx, handle_keypress, &game);
	mlx_loop(render.mlx);    // start the MLX event loop
	cleanup(&game, &render); // clean up resources before exiting
	return (EXIT_SUCCESS);   // return success status
}
