/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:56:44 by tbolsako          #+#    #+#             */
/*   Updated: 2024/11/12 09:05:02 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_print_format(const char specifier, va_list ap)
{
	if (specifier == 'c')
		return (ft_print_char(va_arg(ap, int)));
	else if (specifier == 's')
		return (ft_print_str(va_arg(ap, char *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_print_digit(va_arg(ap, int)));
	else if (specifier == 'x')
		return (ft_print_hex((long)va_arg(ap, unsigned int),
				"0123456789abcdef"));
	else if (specifier == 'p')
		return (ft_print_pointer((long)va_arg(ap, unsigned long long),
				"0123456789abcdef"));
	else if (specifier == 'u')
		return (ft_print_unsigned(va_arg(ap, unsigned int)));
	else if (specifier == 'X')
		return (ft_print_hex((long)va_arg(ap, unsigned int),
				"0123456789ABCDEF"));
	else if (specifier == '%')
		return (write(1, "%", 1));
	return (-1);
}
