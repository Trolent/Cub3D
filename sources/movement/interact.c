/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:50:59 by trolland          #+#    #+#             */
/*   Updated: 2025/04/18 08:47:47 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keycodes.h"
#include "movement.h"
#include <math.h>

void	ft_interact(t_data *infos)
{
	int		x;
	int		y;
	double	interact_x;
	double	interact_y;

	interact_x = infos->player.pos_x + cos(infos->player.degrees * M_PI
			/ 180.0);
	interact_y = infos->player.pos_y + sin(infos->player.degrees * M_PI
			/ 180.0);
	x = (int)interact_x;
	y = (int)interact_y;
	if (infos->map[y][x] == '2')
		infos->map[y][x] = '3';
	else if (infos->map[y][x] == '3')
		infos->map[y][x] = '2';
}

int	door_key(int keycode, t_data *infos)
{
	printf("reading keycode: %d\n", keycode);
	if (keycode == E_KEY)
	{
		printf("E key pressed\n");
		ft_interact(infos);
	}
	return (0);
}
