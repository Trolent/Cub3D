/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaetano <acaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 00:17:21 by acaetano          #+#    #+#             */
/*   Updated: 2024/10/25 17:15:04 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t			len;

	len = 0;
	while (1)
	{
		if (!s[0])
			return (len);
		if (!s[1])
			return (len + 1);
		if (!s[2])
			return (len + 2);
		if (!s[3])
			return (len + 3);
		if (!s[4])
			return (len + 4);
		if (!s[5])
			return (len + 5);
		if (!s[6])
			return (len + 6);
		if (!s[7])
			return (len + 7);
		s += 8;
		len += 8;
	}
	return (len);
}
