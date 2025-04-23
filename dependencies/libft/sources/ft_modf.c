/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:34:45 by trolland          #+#    #+#             */
/*   Updated: 2025/04/14 16:35:04 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_modf(double x, double *iptr)
{
	double	frac_part;

	if (iptr)
		*iptr = (int)x;
	frac_part = x - (int)x;
	return (frac_part);
}
