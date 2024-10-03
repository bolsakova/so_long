/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:46:35 by tbolsako          #+#    #+#             */
/*   Updated: 2024/03/19 14:50:14 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	const unsigned char	*s1;
	size_t				i;

	s1 = s;
	i = 0;
	while (i < len)
	{
		if (s1[i] == (unsigned char)c)
			return ((void *)(s1 + i));
		i++;
	}
	return (NULL);
}
// #include <stdio.h>

// int	main(void)
// {
// 	const char *str = "Sunny day";
// 	char *find = ft_memchr(str, 'y', 10);

// 	if (find != NULL)
// 		printf("%c\n", *find);
// 	else
// 		printf("\n");
// 	return (0);
// }
