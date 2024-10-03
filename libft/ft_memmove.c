/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:33:08 by tbolsako          #+#    #+#             */
/*   Updated: 2024/03/19 14:50:22 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *source, size_t len)
{
	const char	*source1;
	char		*dest1;

	dest1 = dest;
	source1 = source;
	if (dest1 < source1)
	{
		while (len > 0)
		{
			*dest1++ = *source1++;
			len--;
		}
	}
	else if (dest1 > source1)
	{
		dest1 += len;
		source1 += len;
		while (len > 0)
		{
			*(--dest1) = *(--source1);
			len--;
		}
	}
	return (dest);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char	str[10] = "Hey, Mom!";

// 	ft_memmove(str + 5, str, 3);
// 	printf("%s\n", str);
// 	return (0);
// }
