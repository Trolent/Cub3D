/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_dpf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaetano <acaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:34:54 by acaetano          #+#    #+#             */
/*   Updated: 2024/10/04 14:38:48 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	print_nil(int fd, int *len)
{
	if (write(fd, "(nil)", 5) < 5)
		return (-1);
	*len += 5;
	return (0);
}

size_t	set_div(size_t ads)
{
	size_t	div;

	div = 1;
	while (ads / div >= 16)
		div *= 16;
	return (div);
}

int	write_ads(int fd, int *len, size_t div, size_t ads)
{
	char	*lbase;

	lbase = "0123456789abcdef";
	while (div > 0)
	{
		if (write(fd, &lbase[ads / div], 1) < 1)
			return (-1);
		*len += 1;
		ads %= div;
		div /= 16;
	}
	return (0);
}

int	ft_putptr_dpf(int fd, va_list args, int *len)
{
	size_t	ads;
	size_t	div;

	ads = va_arg(args, size_t);
	if (!ads)
		return (print_nil(fd, len));
	else if (write(fd, "0x", 2) < 2)
		return (-1);
	*len += 2;
	div = set_div(ads);
	return (write_ads(fd, len, div, ads));
}
