/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:02:16 by tbolsako          #+#    #+#             */
/*   Updated: 2024/03/24 18:34:45 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list_new;

	list_new = (t_list *)malloc(sizeof(t_list));
	if (list_new)
	{
		list_new->content = content;
		list_new->next = NULL;
	}
	return (list_new);
}
