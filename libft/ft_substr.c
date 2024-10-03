/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:43:31 by tbolsako          #+#    #+#             */
/*   Updated: 2024/03/23 13:18:16 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	i;
	size_t	str_len;
	size_t	substr_len;
	char	*substr;

	i = 0;
	str_len = ft_strlen(str);
	substr_len = len;
	if (!str)
		return (NULL);
	if (start >= str_len)
		return (ft_strdup(""));
	if (substr_len > str_len - start)
		substr_len = str_len - start;
	substr = (char *)malloc((substr_len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	while (i < substr_len)
	{
		substr[i] = str[start + i];
		i++;
	}
	substr[substr_len] = '\0';
	return (substr);
}
// #include <stdio.h>

// int	main(void)
// {
// 	const char *str = "Sunny day!";
// 	char *substr = ft_substr(str, 3, 4);

// 	if (substr != NULL)
// 	{
// 		printf("%s\n", substr);
// 		free(substr);
// 	}
// 	else
// 	{
// 		printf("\n");
// 	}
// 	return (0);
// }
