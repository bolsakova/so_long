/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:53:00 by tbolsako          #+#    #+#             */
/*   Updated: 2024/04/25 19:15:20 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int num)
{
	int	i;

	i = 0;
	if (num < 10)
	{
		ft_print_char(num + 48);
		return (1);
	}
	i += ft_print_digit(num / 10);
	ft_print_char(num % 10 + 48);
	return (i + 1);
}
