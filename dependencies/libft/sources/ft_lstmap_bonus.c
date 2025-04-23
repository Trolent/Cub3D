/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaetano <acaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:58:35 by acaetano          #+#    #+#             */
/*   Updated: 2024/06/12 15:57:26 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstcpy;
	t_list	*new_node;

	lstcpy = NULL;
	new_node = NULL;
	if (!lst || !f || !del)
		return (NULL);
	new_node = ft_lstnew(f(lst->content));
	if (!new_node)
		return (NULL);
	lstcpy = new_node;
	lst = lst->next;
	while (lst)
	{
		new_node->next = ft_lstnew(f(lst->content));
		if (!new_node->next)
		{
			ft_lstclear(&lstcpy, del);
			return (NULL);
		}
		new_node = new_node->next;
		ft_lstadd_back(&lstcpy, new_node);
		lst = lst->next;
	}
	return (lstcpy);
}
