/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inception <inception@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:01:13 by trolland          #+#    #+#             */
/*   Updated: 2025/04/23 10:47:20 by inception        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	set_north(double *degrees)
{
	*degrees = 270;
}

void	set_south(double *degrees)
{
	*degrees = 90;
}

void	set_east(double *degrees)
{
	*degrees = 0;
}

void	set_west(double *degrees)
{
	*degrees = 180;
}

int	key_dir(int keycode)
{
	int			i;
	const int	key[4] = {'N', 'S', 'E', 'W'};

	i = -1;
	while (++i < 4)
		if (keycode == key[i])
			return (i);
	return (-1);
}
