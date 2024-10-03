/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:29:39 by tbolsako          #+#    #+#             */
/*   Updated: 2024/03/19 20:46:11 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	unsigned char	str1;
	unsigned char	str2;
	size_t			i;

	i = 0;
	while ((s1[i] || s2[i]) && n > i)
	{
		str1 = (unsigned char)s1[i];
		str2 = (unsigned char)s2[i];
		if (str1 != str2)
			return (str1 - str2);
		i++;
	}
	return (0);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char	s1[10] = "123";
// 	char	s2[] = "123457";
// 	size_t	n = 5;

// 	printf("%d\n", ft_strncmp(s1, s2, n));
// }
