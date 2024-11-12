/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:20:33 by tbolsako          #+#    #+#             */
/*   Updated: 2024/04/27 13:05:12 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_print_char(int c);
int	ft_print_str(char *str);
int	ft_print_digit(int num);
int	ft_print_unsigned(unsigned int num);
int	ft_print_hex(unsigned long long num, const char *base);
int	ft_print_pointer(unsigned long long num, const char *base);
int	ft_print_format(char specifier, va_list ap);
int	ft_printf(const char *format, ...);

#endif
