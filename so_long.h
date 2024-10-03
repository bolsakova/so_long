/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:22:58 by tbolsako          #+#    #+#             */
/*   Updated: 2024/10/03 16:35:41 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// minilibx library
# include "MLX42/include/MLX42/MLX42.h"

// file control options library
# include <fcntl.h>

// standard libraries
# include <stdlib.h>
# include <unistd.h>

// define the size of each tile in pixels
# define TILE_SIZE 32

// the player's starting position
# define PLAYER 'P'

// a map exit
# define EXIT 'E'

// collectible items
# define COLLECTIBLE 'C'

// walls
# define WALL '1'

// an empty space
# define EMPTY '0'

#endif
