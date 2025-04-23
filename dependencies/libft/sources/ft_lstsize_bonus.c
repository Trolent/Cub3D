/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaetano <acaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:23:23 by acaetano          #+#    #+#             */
/*   Updated: 2025/02/11 15:50:07 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_lstsize(t_list *lst)
{
	ssize_t	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
		if (i < 0)
			break ;
	}
	return (i);
}
