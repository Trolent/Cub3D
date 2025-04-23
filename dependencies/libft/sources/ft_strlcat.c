/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaetano <acaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:32:47 by acaetano          #+#    #+#             */
/*   Updated: 2023/11/14 12:46:15 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	slen;
	size_t	dlen;

	slen = ft_strlen(src);
	if (size == 0)
		return (slen);
	dlen = ft_strlen(dst);
	if (size < dlen)
		return (slen + size);
	if (dlen == size)
		return (slen + dlen);
	if (slen < size - dlen)
		ft_memcpy(&dst[dlen], src, slen + 1);
	else
	{
		ft_memcpy(&dst[dlen], src, size - 1);
		dst[size -1] = 0;
	}
	return (dlen + slen);
}
