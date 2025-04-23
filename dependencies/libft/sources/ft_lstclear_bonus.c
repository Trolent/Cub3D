/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaetano <acaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:45:34 by acaetano          #+#    #+#             */
/*   Updated: 2023/10/17 10:23:57 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_node;
	t_list	*current;

	next_node = NULL;
	current = NULL;
	if (lst && del && *lst)
	{
		current = *lst;
		while (current)
		{
			next_node = current->next;
			del(current->content);
			free(current);
			current = next_node;
		}
		*lst = NULL;
	}
}
