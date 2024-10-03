/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:41:30 by tbolsako          #+#    #+#             */
/*   Updated: 2024/03/24 13:24:59 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numlen(int n)
{
	size_t	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n / 10 != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*allocate_str(char *str, size_t len)
{
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*str;
	int		sign;

	len = ft_numlen(n);
	str = NULL;
	sign = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	str = allocate_str(str, len);
	if (!str)
		return (NULL);
	while (len-- > 0)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int		num = -150;
// 	char	*result = ft_itoa(num);

// 	printf("%s\n", result);
// 	return (0);
// }
