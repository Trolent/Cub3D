/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaetano <acaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:51:15 by acaetano          #+#    #+#             */
/*   Updated: 2023/10/02 11:24:56 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = NULL;
	if (s)
	{
		str = ft_strdup(s);
		if (!str)
			return (NULL);
		while (str[i] && s)
		{
			str[i] = f(i, str[i]);
			i++;
		}
	}
	return (str);
}
