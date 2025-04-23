/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaetano <acaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:47:17 by acaetano          #+#    #+#             */
/*   Updated: 2023/11/13 14:36:17 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_sign_fd(long *nb, int fd)
{
	*nb = -*nb;
	ft_putchar_fd(45, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	int		digit;

	if (fd >= 0)
	{
		nb = n;
		digit = 1;
		if (nb < 0)
			ft_sign_fd(&nb, fd);
		while (nb / digit >= 10)
			digit *= 10;
		while (digit > 0)
		{
			ft_putchar_fd(nb / digit + 48, fd);
			nb %= digit;
			digit /= 10;
		}
	}
}
