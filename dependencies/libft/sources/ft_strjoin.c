/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaetano <acaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:59:46 by acaetano          #+#    #+#             */
/*   Updated: 2024/11/18 18:55:15 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		len1;
	size_t		len2;
	char		*s3;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		s3 = malloc(sizeof(char) * (len1 + len2) + 1);
		if (!s3)
			return (NULL);
		else
		{
			ft_memcpy(s3, s1, len1);
			ft_memcpy(&s3[len1], s2, len2);
			s3[len1 + len2] = 0;
			return (s3);
		}
	}
	else
		return (NULL);
}
