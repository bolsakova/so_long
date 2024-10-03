/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:20:43 by tbolsako          #+#    #+#             */
/*   Updated: 2024/03/20 19:22:39 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int a)
{
	const char	*str1;

	str1 = str;
	while (*str)
		str++;
	if ((char)a == '\0')
		return ((char *)str);
	while (str1 <= str)
	{
		if (*str == (char)a)
			return ((char *)str);
		str--;
	}
	return (NULL);
}
// #include <stdio.h>

// int	main(void)
// {
// 	const char *str = "y, Sunny";
// 	char *last = ft_strrchr(str, 'y');

// 	if (last != NULL)
// 		printf("%ld\n", last - str);
// 	else
// 		printf("\n");
// 	return (0);
// }