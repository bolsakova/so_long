/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:12:46 by tbolsako          #+#    #+#             */
/*   Updated: 2024/03/24 20:44:22 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t len)
{
	const unsigned char	*source1;
	unsigned char		*dest1;

	dest1 = dest;
	source1 = source;
	if (dest == NULL && source == NULL)
		return (dest);
	while (len--)
	{
		*dest1 = *source1;
		source1++;
		dest1++;
	}
	return (dest);
}
// #include <stdio.h>

// int	main(void)
// {
// 	const char	source[10];
// 	char		dest[10];

// 	ft_memcpy(dest, "strstr", 4);
// 	printf("%s\n", dest);
// 	return (0);
// }
