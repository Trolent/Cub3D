/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_dpf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaetano <acaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:59:36 by acaetano          #+#    #+#             */
/*   Updated: 2024/10/04 14:53:46 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ft_putunbr_dpf(int fd, va_list args, int *len)
{
	unsigned int	div;
	unsigned int	nbr;
	unsigned int	c;

	div = 1;
	nbr = va_arg(args, unsigned int);
	while (nbr / div >= 10)
		div *= 10;
	while (div > 0)
	{
		c = nbr / div + '0';
		if (write(fd, &c, 1) < 1)
			return (-1);
		*len += 1;
		nbr %= div;
		div /= 10;
	}
	return (0);
}
