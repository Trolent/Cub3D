/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_dpf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaetano <acaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:37:42 by acaetano          #+#    #+#             */
/*   Updated: 2024/10/04 13:58:15 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ft_putnbr_dpf(int fd, va_list args, int *len)
{
	long	div;
	long	nbr;
	long	c;

	div = 1;
	nbr = va_arg(args, int);
	if (nbr < 0)
	{
		if (write(fd, "-", 1) <= 0)
			return (-1);
		*len += 1;
		nbr = -nbr;
	}
	while (nbr / div >= 10)
		div *= 10;
	while (div > 0)
	{
		c = nbr / div + 48;
		if (write(fd, &c, 1) <= 0)
			return (-1);
		*len += 1;
		nbr %= div;
		div /= 10;
	}
	return (0);
}
