/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaetano <acaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 10:07:51 by acaetano          #+#    #+#             */
/*   Updated: 2025/01/13 19:34:37 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*ft_makestr(char *str, int size)
{
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	return (str);
}

static void	ft_sign(long *nb, int *size, int *sign)
{
	*nb = -*nb;
	*size += *size;
	*sign += 1;
}

static char	*ft_intostr(long nb, long digit, int size, int sign)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	str = ft_makestr(str, size);
	if (!str)
		return (NULL);
	if (sign)
	{
		str[0] = 45;
		i++;
	}
	while (digit > 0)
	{
		str[i] = (nb / digit) + 48;
		nb %= digit;
		digit /= 10;
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_itoa(int n)
{
	long	nb;
	long	digit;
	int		sign;
	int		size;

	nb = n;
	sign = 0;
	size = 1;
	digit = 1;
	if (nb < 0)
		ft_sign(&nb, &size, &sign);
	while (nb / digit >= 10)
	{
		digit *= 10;
		size++;
	}
	return (ft_intostr(nb, digit, size, sign));
}
