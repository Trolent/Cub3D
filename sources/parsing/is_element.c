/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_element.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaetano <acaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:41:03 by acaetano          #+#    #+#             */
/*   Updated: 2025/04/21 16:10:19 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*elements(int i)
{
	const char	*elements[] = {
		"NO",
		"SO",
		"EA",
		"WE",
		"DO",
		"C",
		"F",
		NULL,
	};

	return ((char *)elements[i]);
}

bool	is_element(char *str)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]))
			i++;
		j = 0;
		while (elements(j))
		{
			len = ft_strlen(elements(j));
			if (!ft_strncmp(&str[i], elements(j), len)
				&& (str[i + len] == ' ' || str[i + len] == '\t'))
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}
