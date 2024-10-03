/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:57:09 by tbolsako          #+#    #+#             */
/*   Updated: 2024/03/24 15:27:58 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *source, size_t size)
{
	size_t	dest_len;
	size_t	source_len;
	size_t	i;

	dest_len = 0;
	source_len = 0;
	i = 0;
	while (dest[dest_len] && dest_len < size)
		dest_len++;
	while (source[source_len])
		source_len++;
	if (size == 0)
		return (source_len);
	if (dest_len >= size)
		return (size + source_len);
	while (source[i] && dest_len + i < size - 1)
	{
		dest[dest_len + i] = source[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + source_len);
}
// #include <stdio.h>

// int	main(void)
// {
// 	const char	source[20] = "abc";
// 	char		dest[20] = "ABC";
// 	size_t		res;

// 	res = ft_strlcat(dest, source, sizeof(dest));
// 	printf("%zu\n", res);
// }