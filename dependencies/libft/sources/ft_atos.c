/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaetano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:19:12 by acaetano          #+#    #+#             */
/*   Updated: 2025/01/15 16:56:44 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_atos(char *str, bool *overflow)
{
	ssize_t	nb;
	ssize_t	pow;
	char	*tmp;

	nb = 0;
	pow = 1;
	tmp = str;
	while (*tmp)
	{
		pow *= 10;
		if (pow < 0)
			return (*overflow = true, 2);
		tmp++;
	}
	tmp = str;
	while (*tmp)
	{
		pow /= 10;
		nb += ((*tmp) - 48) * pow;
		tmp++;
	}
	if (nb > LONG_MAX || nb < LONG_MIN)
		return (*overflow = true, 2);
	return (*overflow = false, nb);
}
