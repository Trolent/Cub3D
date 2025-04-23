/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaetano <acaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:00:15 by acaetano          #+#    #+#             */
/*   Updated: 2023/11/13 17:53:38 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_startchr(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] && s1 && set)
	{
		while (set[j] && s1[i])
		{
			if (set[j] == s1[i])
			{
				i++;
				j = -1;
			}
			j++;
		}
		return (i);
	}
	return (i);
}

static size_t	ft_endchr(char const *s1, char const *set)
{
	size_t	end;
	size_t	i;

	i = 0;
	end = 0;
	if (s1 && s1[end])
		end = ft_strlen(s1) - 1;
	if (set && s1 && s1[end])
	{
		while (set[i] && s1[end])
		{
			if (set[i] == s1[end] && s1[end])
			{
				if (end == 0)
					return (end);
				end--;
				i = -1;
			}
			i++;
		}
	}
	return (end);
}

static char	*ft_trimcpy(char *trim, char const *s1, size_t start, size_t end)
{
	size_t	i;

	i = 0;
	if (s1[start])
	{
		while (start <= end)
		{
			trim[i] = s1[start];
			start++;
			i++;
		}
	}
	trim[i] = 0;
	return (trim);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tr;
	size_t	end;
	size_t	start;

	tr = NULL;
	if (s1)
	{
		start = ft_startchr(s1, set);
		end = ft_endchr(s1, set);
		if (start > end)
			end = start;
		if (!s1[start])
		{
			tr = malloc(sizeof(char) * 1);
			ft_memset(tr, 0, 1);
			return (tr);
		}
		tr = malloc(sizeof(char) * (end - start + 2));
		if (!tr)
			return (NULL);
		tr = ft_trimcpy(tr, s1, start, end);
		return (tr);
	}
	return (NULL);
}
