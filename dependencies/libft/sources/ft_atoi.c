/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaetano <acaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:26:58 by acaetano          #+#    #+#             */
/*   Updated: 2025/04/21 15:49:33 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswhite(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (c);
	return (0);
}

static int	ft_check(const char *str)
{
	int	i;

	i = 0;
	while (ft_iswhite(str[i]))
		i++;
	if (str[i] == 45 || str[i] == 43 || ft_isdigit(str[i]))
		return (i);
	return (0);
}

int	ft_atoi(const char *str)
{
	long	nb;
	int		i;
	int		sign;

	nb = 0;
	sign = 1;
	i = ft_check(str);
	if (str[i] == 45)
	{
		sign = -sign;
		i++;
	}
	else if (str[i] == 43)
		i++;
	while (ft_isdigit(str[i]))
	{
		nb = nb * 10 + (str[i] - 48) % 10;
		if ((nb > 2147483648 && sign < 0) || (sign > 0 && nb > INT_MAX))
			return (-1);
		i++;
	}
	if (!ft_isdigit(str[i]) && str[i])
		return (-1);
	return (nb * sign);
}
