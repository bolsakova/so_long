/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:48:57 by tbolsako          #+#    #+#             */
/*   Updated: 2024/11/12 09:04:53 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}
