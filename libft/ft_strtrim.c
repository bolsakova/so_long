/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:31:50 by tbolsako          #+#    #+#             */
/*   Updated: 2024/03/23 15:46:03 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_trim_char(char a, const char *set)
{
	while (*set)
	{
		if (*set == a)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	diff;
	char	*trimmed_str;

	start = 0;
	end = ft_strlen(s1);
	if (!*s1)
		return (ft_strdup(""));
	if (!set[0])
		return (ft_strdup(s1));
	while (s1[start] && is_trim_char(s1[start], set))
		start++;
	while (end > start && is_trim_char(s1[end - 1], set))
		end--;
	diff = end - start;
	trimmed_str = (char *)malloc((diff + 1) * sizeof(char));
	if (!trimmed_str)
		return (NULL);
	ft_strlcpy(trimmed_str, s1 + start, diff + 1);
	trimmed_str[diff] = '\0';
	return (trimmed_str);
}

// #include <stdio.h>

// int	main(void)
// {
// 	const char	*str1 = "Sunny day!";
// 	const char	*set = "Suy!";
// 	char		*trimmed_str;

// 	trimmed_str = ft_strtrim(str1, set);
// 	if (trimmed_str != NULL)
// 	{
// 		printf("%s\n", trimmed_str);
// 		free(trimmed_str);
// 	}
// 	else
// 	{
// 		printf("\n");
// 	}
// 	return (0);
// }
