/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atouc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaetano <acaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:06:08 by acaetano          #+#    #+#             */
/*   Updated: 2024/10/08 16:07:32 by acaetano         ###   ########.fr       */
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

int	ft_atouc(const char *str)
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
		i++;
	}
	return (nb * sign);
}
