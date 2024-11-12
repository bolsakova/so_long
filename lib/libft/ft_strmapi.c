/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 13:38:24 by tbolsako          #+#    #+#             */
/*   Updated: 2024/11/12 09:15:01 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*str_new;

	if (!str || !f)
		return (NULL);
	i = 0;
	len = ft_strlen(str);
	str_new = (char *)malloc((len + 1) * sizeof(char));
	if (!str_new)
		return (NULL);
	while (str[i])
	{
		str_new[i] = f(i, str[i]);
		i++;
	}
	str_new[i] = '\0';
	return (str_new);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	str[] = "Hello, World!";
// 	char	*str_new;

// 	str_new = ft_strmapi(str, to_uppercase);
// 	printf("%s\n", str_new);
// 	free(str_new);
// 	return (0);
// }
