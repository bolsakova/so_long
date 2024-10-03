/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolsako <tbolsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 20:13:33 by tbolsako          #+#    #+#             */
/*   Updated: 2024/03/25 12:41:09 by tbolsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	res = NULL;
	new_node = lst;
	while (lst)
	{
		new_content = f(lst->content);
		if (new_content)
		{
			new_node = ft_lstnew(new_content);
			if (!new_node)
			{
				del(new_content);
				ft_lstclear(&res, del);
				return (NULL);
			}
			ft_lstadd_back(&res, new_node);
		}
		lst = lst->next;
	}
	return (res);
}
