/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_minishell_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaetano <acaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:04:11 by acaetano          #+#    #+#             */
/*   Updated: 2024/11/12 15:00:38 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	is_quoted(char c)
{
	static bool	quote;

	if (quote == 0 && (c == '\'' || c == '\"'))
		quote = true;
	else if (quote == 1 && (c == '\'' || c == '\"'))
		quote = false;
	return (quote);
}

size_t	find_end_quote(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == c && i > 0)
			return (i + 1);
		i++;
	}
	return (i);
}

size_t	find_last_quote(const char *s, char c)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(s);
	i = len;
	while (s && s[i])
	{
		if (s[i] == c && i > 0)
			return (i);
		i--;
	}
	return (len);
}
