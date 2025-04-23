/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaetano <acaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:19:37 by acaetano          #+#    #+#             */
/*   Updated: 2024/10/25 17:38:17 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t	size)
{
	char	*dup;

	if (!s1)
		return (NULL);
	dup = ft_calloc(sizeof(char), (size + 1));
	if (dup == NULL)
		return (NULL);
	ft_strlcpy(dup, s1, size + 1);
	return (dup);
}
