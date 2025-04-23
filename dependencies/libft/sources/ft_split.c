/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaetano <acaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:27:58 by acaetano          #+#    #+#             */
/*   Updated: 2025/04/18 20:21:36 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countstr(char const *s, char *sep)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] && !ft_isseparator(s[i], sep))
		{
			count++;
			while (s[i] && !ft_isseparator(s[i], sep))
				i++;
		}
		else
			i++;
	}
	return (count);
}

static void	ft_protect(char **splitter, size_t i)
{
	while (i > 0)
	{
		free(splitter[i]);
		i--;
	}
	free(splitter[0]);
	free(splitter);
}

static char	*ft_mallndup(const char *s, size_t start, size_t end)
{
	size_t	len;
	char	*sp;

	len = end - start;
	sp = malloc(sizeof(char) * (len + 1));
	if (!sp)
		return (NULL);
	ft_strlcpy(sp, &s[start], len + 1);
	return (sp);
}

static char	**ft_findsubstr(char **splitter, const char *s, char *sep)
{
	size_t	i;
	size_t	k;
	size_t	start;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] && !ft_isseparator(s[i], sep))
		{
			start = i;
			while (s[i] && !ft_isseparator(s[i], sep))
				i++;
			splitter[k] = ft_mallndup(s, start, i);
			if (!splitter[k])
			{
				ft_protect(splitter, k);
				return (NULL);
			}
			k++;
		}
		else
			i++;
	}
	return (splitter);
}

char	**ft_split(char const *s, char *sep)
{
	char	**splitter;
	size_t	count;

	splitter = NULL;
	if (!s)
		return (NULL);
	count = ft_countstr(s, sep);
	splitter = malloc(sizeof(char *) * (count + 1));
	if (!splitter)
		return (NULL);
	splitter = ft_findsubstr(splitter, s, sep);
	if (!splitter)
		return (NULL);
	splitter[count] = NULL;
	return (splitter);
}
