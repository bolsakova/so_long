/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:56:35 by tbolsako          #+#    #+#             */
/*   Updated: 2024/03/19 21:15:33 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *ptr)
{
	size_t	i;
	int		sign;
	int		result;

	i = 0;
	sign = 1;
	result = 0;
	while (ptr[i] && ((ptr[i] >= 9 && ptr[i] <= 13) || ptr[i] == 32))
		i++;
	if (ptr[i] == '+' || ptr[i] == '-')
	{
		if (ptr[i + 1] == '+' || ptr[i + 1] == '-' || !('0' <= ptr[i + 1]
				&& ptr[i + 1] <= '9'))
			return (0);
		if (ptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ptr[i] && ptr[i] >= '0' && ptr[i] <= '9')
	{
		result = (result * 10) + (ptr[i] - '0');
		i++;
	}
	return (result * sign);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char	str[] = "-56487";
// 	int	result = ft_atoi(str);

// 	printf("%d\n", result);
// 	return (0);
// }
