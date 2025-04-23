/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaetano <acaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:08:29 by acaetano          #+#    #+#             */
/*   Updated: 2024/10/04 14:21:03 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static int	put_stray_specifier(int fd, int c, int *len)
{
	if (c != '%')
		*len += write(fd, "%", 1);
	*len += write(fd, &c, 1);
	return (0);
}

static int	ft_flags(int fd, int i, int *len, va_list args)
{
	static int	(*f[256])(int fd, va_list args, int *len);

	f['c'] = ft_putchar_dpf;
	f['s'] = ft_putstr_dpf;
	f['p'] = ft_putptr_dpf;
	f['d'] = ft_putnbr_dpf;
	f['i'] = ft_putnbr_dpf;
	f['u'] = ft_putunbr_dpf;
	f['x'] = ft_putnbr_lbase_dpf;
	f['X'] = ft_putnbr_ubase_dpf;
	if (!f[i])
		return (put_stray_specifier(fd, i, len));
	return (f[i](fd, args, len));
}

int	ft_dprintf(int fd, const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (!format[i + 1] || ft_flags(fd, format[i + 1], &len, args) < 0)
				return (-1);
			i += 2;
		}
		else if (write(fd, &format[i++], 1) < 1)
			return (-1);
		else
			len += 1;
	}
	va_end(args);
	return (len);
}
