/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:24:59 by tbolsako          #+#    #+#             */
/*   Updated: 2024/11/12 09:14:38 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dup;
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (str[len])
		len++;
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[len] = '\0';
	return (dup);
}
// #include <stdio.h>

// int	main(void)
// {
// 	const char	*str = "Sunny day!";
// 	char		*dup = ft_strdup(str);

// 	if (dup == NULL)
// 		printf("NULL\n");
// 	else
// 	{
// 		printf("%s\n", dup);
// 		free(dup);
// 	}
// 	return (0);
// }
