/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:20:31 by tbolsako          #+#    #+#             */
/*   Updated: 2024/03/19 14:50:30 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int a, size_t len)
{
	char	*ptr;

	ptr = str;
	while (len > 0)
	{
		*ptr = (unsigned char)a;
		ptr++;
		len--;
	}
	return (str);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char	str[10];

// 	ft_memset(str, 'a', 7);
// 	printf("%s\n", str);
// 	return (0);
// }
