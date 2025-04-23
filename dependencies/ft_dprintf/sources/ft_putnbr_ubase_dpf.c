/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ubase_dpf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaetano <acaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:25:15 by acaetano          #+#    #+#             */
/*   Updated: 2024/10/04 14:00:46 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ft_putnbr_ubase_dpf(int fd, va_list args, int *len)
{
	unsigned int	nbr;
	unsigned int	div;
	char			*ubase;

	div = 1;
	ubase = "0123456789ABCDEF";
	nbr = va_arg(args, unsigned int);
	while (nbr / div >= 16)
		div *= 16;
	while (div > 0)
	{
		if (write(fd, &ubase[nbr / div], 1) <= 0)
			return (-1);
		nbr %= div;
		div /= 16;
		*len += 1;
	}
	return (0);
}
