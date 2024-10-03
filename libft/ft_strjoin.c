/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 13:21:16 by tbolsako          #+#    #+#             */
/*   Updated: 2024/03/23 14:07:04 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new_str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1)
			* sizeof(char));
	if (!new_str)
		return (NULL);
	while (s1[i])
		new_str[k++] = s1[i++];
	while (s2[j])
		new_str[k++] = s2[j++];
	new_str[k++] = '\0';
	return (new_str);
}
// #include <stdio.h>

// int	main(void)
// {
// 	const char	*str1 = "Sunny ";
// 	const char	*str2 = "day!";
// 	char		*new_str;

// 	new_str = ft_strjoin(str1, str2);
// 	if (new_str != NULL)
// 	{
// 		printf("%s\n", new_str);
// 		free(new_str);
// 	}
// 	else
// 	{
// 		printf("\n");
// 	}
// 	return (0);
// }
