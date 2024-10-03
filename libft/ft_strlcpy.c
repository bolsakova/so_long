/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:32:47 by tbolsako          #+#    #+#             */
/*   Updated: 2024/03/15 16:32:47 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *source, size_t size)
{
	size_t	i;
	size_t	source_len;

	i = 0;
	source_len = 0;
	while (source[source_len])
		source_len++;
	if (size == 0)
		return (source_len);
	while (i < size - 1 && source[i])
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = '\0';
	return (source_len);
}

// #include <stdio.h>

// int	main(void)
// {
// 	const char source[10];
// 	char dest[10];

// 	int a = ft_strlcpy(dest, "strst", sizeof(dest));
// 	printf("%d\n", a);
// 	return (0);
// }
