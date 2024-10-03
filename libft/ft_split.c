/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:17:04 by tbolsako          #+#    #+#             */
/*   Updated: 2024/03/23 19:46:49 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	*allocate_word(const char *str, char c)
{
	char	*word;
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	word = (char *)malloc((i + 1) * sizeof(char));
	if (!word)
		return (NULL);
	ft_strlcpy(word, str, i + 1);
	return (word);
}

static char	**allocate_split(char **split, char const *str, char a,
		size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		while (*str && *str == a)
			str++;
		split[i] = allocate_word(str, a);
		if (!split[i])
		{
			while (i > 0)
				free(split[--i]);
			free(split);
			return (NULL);
		}
		while (*str && *str != a)
			str++;
		i++;
	}
	split[count] = NULL;
	return (split);
}

char	**ft_split(char const *str, char a)
{
	char	**split;
	size_t	count;

	if (!str)
		return (NULL);
	count = count_words(str, a);
	split = (char **)malloc((count + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	return (allocate_split(split, str, a, count));
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*s = "str str str";
// 	char	c = ' ';
// 	int		count = count_words(s, c);

// 	printf("%d\n", count);
// 	return (0);
// }