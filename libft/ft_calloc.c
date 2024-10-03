/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 19:17:49 by tbolsako          #+#    #+#             */
/*   Updated: 2024/03/19 14:49:11 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	unsigned char	*byte_ptr;
	size_t			i;
	size_t			total;
	void			*ptr;

	total = num * size;
	ptr = malloc(total);
	if (ptr == NULL)
		return (NULL);
	byte_ptr = (unsigned char *)ptr;
	i = 0;
	while (i < total)
	{
		byte_ptr[i] = 0;
		i++;
	}
	return (ptr);
}
// #include <stdio.h>

// int	main(void)
// {
// 	size_t	num = 6;
// 	size_t	size = sizeof(int);
// 	int		*a = (int *)ft_calloc(num, size);

// 	if (a != NULL)
// 	{
// 		printf("\n");
// 		size_t	i = 0;
// 		while (i < num)
// 		{
// 			a[i] = i + 1;
// 			i++;
// 		}
// 		i = 0;
// 		while (i < num)
// 		{
// 			printf("%d ", a[i]);
// 			i++;
// 		}
// 		free(a);
// 	}
// 	else
// 	{
// 	}
// 	return (0);
// }
