/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaetano <acaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:07:56 by acaetano          #+#    #+#             */
/*   Updated: 2023/11/13 14:22:20 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = len - 1;
	if (src == dst || len == 0)
		return (dst);
	if (src > dst)
	{
		ft_memcpy(dst, src, len);
		return (dst);
	}
	while (src < dst && i > 0)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i--;
	}
	((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
	return (dst);
}
