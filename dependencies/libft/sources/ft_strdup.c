/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaetano <acaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:34:25 by acaetano          #+#    #+#             */
/*   Updated: 2023/09/29 13:15:26 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	size;

	size = ft_strlen(s1);
	dup = malloc(sizeof(char) * (size + 1));
	if (dup == NULL)
		return (NULL);
	ft_strlcpy(dup, s1, size + 1);
	return (dup);
}
