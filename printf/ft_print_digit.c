/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:51:28 by tbolsako          #+#    #+#             */
/*   Updated: 2024/04/25 19:41:57 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_digit(int num)
{
	int		i;

	i = 0;
	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (num < 0)
	{
		ft_print_char('-');
		num = -num;
		i++;
	}
	if (num < 10)
	{
		ft_print_char(num + 48);
		return (i + 1);
	}
	i += ft_print_digit(num / 10);
	ft_print_char(num % 10 + 48);
	return (i + 1);
}
