/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:14:50 by tbolsako          #+#    #+#             */
/*   Updated: 2024/11/08 15:46:23 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *buffer, char const *tmp)
{
	char	*final;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!buffer || !tmp)
		return (NULL);
	i = 0;
	j = 0;
	k = f_strlen(buffer) + f_strlen(tmp);
	final = (char *)malloc((k + 1) * sizeof(char));
	if (!final)
		return (NULL);
	while (buffer[i])
	{
		final[i] = buffer[i];
		i++;
	}
	while (tmp[j])
		final[i++] = tmp[j++];
	final[k] = '\0';
	return (final);
}

char	*ft_strchr(const char *buffer, int a)
{
	while (*buffer != (char)a)
	{
		if (*buffer == '\0')
			return (NULL);
		buffer++;
	}
	return ((char *)buffer);
}

int	f_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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
