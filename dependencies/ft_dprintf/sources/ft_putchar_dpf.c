/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_dpf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaetano <acaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:14:29 by acaetano          #+#    #+#             */
/*   Updated: 2024/10/04 13:43:35 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ft_putchar_dpf(int fd, va_list args, int *len)
{
	int		c;
	ssize_t	r;

	c = va_arg(args, int);
	r = write (fd, &c, 1);
	if (r <= 0)
		return (-1);
	return (*len += 1);
}
