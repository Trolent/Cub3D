/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaetano <acaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:21:46 by acaetano          #+#    #+#             */
/*   Updated: 2023/11/14 10:58:19 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	size_t	n;

	n = count * size;
	if (n && (n / count != size))
		return (NULL);
	mem = malloc(n);
	if (!mem)
		return (NULL);
	ft_bzero(mem, n);
	return (mem);
}
