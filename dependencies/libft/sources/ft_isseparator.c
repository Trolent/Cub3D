/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isseparator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaetano <acaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:44:56 by acaetano          #+#    #+#             */
/*   Updated: 2025/02/18 17:10:31 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_isseparator(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep && sep[i])
	{
		if (!c || c == sep[i])
			return (true);
		i++;
	}
	return (false);
}
