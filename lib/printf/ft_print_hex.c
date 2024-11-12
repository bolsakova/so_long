/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:53:57 by tbolsako          #+#    #+#             */
/*   Updated: 2024/11/12 09:05:05 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_print_hex(unsigned long long num, const char *base)
{
	int	i;

	i = 0;
	if (num < 16)
	{
		return (write(1, &base[num % 16], 1));
	}
	i += ft_print_hex(num / 16, base);
	write(1, &base[num % 16], 1);
	return (i + 1);
}
