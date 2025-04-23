/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_dpf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaetano <acaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:37:36 by acaetano          #+#    #+#             */
/*   Updated: 2024/10/04 14:53:15 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"
//#include "libft.h"

static long	ft_strlen(char *str)
{
	long	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_putstr_dpf(int fd, va_list args, int *len)
{
	long	slen;
	char	*str;

	str = va_arg(args, char *);
	if (!str)
	{
		if (write(fd, "(null)", 6) < 6)
			return (-1);
		*len += 6;
	}
	else
	{
		slen = ft_strlen(str);
		if (write(fd, str, slen) < slen)
			return (-1);
		*len += slen;
	}
	return (0);
}
