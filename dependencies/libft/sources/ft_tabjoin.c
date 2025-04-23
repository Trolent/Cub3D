/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaetano <acaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:15:54 by acaetano          #+#    #+#             */
/*   Updated: 2025/02/12 15:05:14 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static char	**copy_tab(char **src, char **dst)
{
	size_t	i;

	i = 0;
	while (src && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (src)
		free(src);
	return (dst);
}

static char	**create_new_tab(char **tab, char *str)
{
	size_t	size;
	char	**new;

	size = 0;
	while (tab && tab[size])
		size++;
	new = ft_calloc((size + 2), sizeof(char **));
	if (!new)
		return (tab);
	else
	{
		new = copy_tab(tab, new);
		new[size] = str;
		if (!new[size])
			return (free_tab(new), NULL);
	}
	return (new);
}

char	**ft_tabjoin(char **tab, char *str)
{
	char	**new_tab;

	if (!str)
		return (tab);
	new_tab = create_new_tab(tab, str);
	if (!new_tab)
		return (tab);
	return (new_tab);
}
