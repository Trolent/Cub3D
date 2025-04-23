/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaetano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:34:36 by acaetano          #+#    #+#             */
/*   Updated: 2025/02/10 20:17:02 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_subzero(char *sub)
{
	sub = ft_calloc(sizeof(char), 1);
	if (!sub)
		return (NULL);
	return (sub);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;

	sub = NULL;
	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen || (!start && !len))
	{
		sub = ft_subzero(sub);
		if (!sub)
			return (NULL);
		return (sub);
	}
	if (len > (slen - start))
		len = slen - start;
	sub = malloc(sizeof(char) * len + 1);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}
