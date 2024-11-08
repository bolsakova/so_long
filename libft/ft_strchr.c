/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:07:36 by tbolsako          #+#    #+#             */
/*   Updated: 2024/11/08 18:45:28 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int a)
{
	while (*str != (char)a)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return ((char *)str);
}

// #include <stdio.h>

// int	main(void)
// {
// 	const char *str = "y, Sunny";
// 	char *find = ft_strchr(str, 'y');

// 	if (find != NULL)
// 		printf("%s\n", str);
// 	else
// 		printf("\n");
// 	return (0);
// }
