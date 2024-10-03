/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:03:20 by tbolsako          #+#    #+#             */
/*   Updated: 2024/03/19 14:48:58 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t len)
{
	char	*ptr;

	ptr = str;
	while (len > 0)
	{
		*ptr = 0;
		ptr++;
		len--;
	}
}
// #include <stdio.h>

// int	main(void)
// {
// 	char	str[10];

// 	ft_bzero(str, 7);
// 	printf("%s\n", str);
// 	return (0);
// }
