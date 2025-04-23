/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_lbase_dpf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaetano <acaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:31:23 by acaetano          #+#    #+#             */
/*   Updated: 2024/10/04 13:59:12 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ft_putnbr_lbase_dpf(int fd, va_list args, int *len)
{
	unsigned int	nbr;
	unsigned int	div;
	char			*ubase;

	div = 1;
	ubase = "0123456789abcdef";
	nbr = va_arg(args, unsigned int);
	while (nbr / div >= 16)
		div *= 16;
	while (div > 0)
	{
		if (write(fd, &ubase[nbr / div], 1) <= 0)
			return (-1);
		*len += 1;
		nbr %= div;
		div /= 16;
	}
	return (0);
}
