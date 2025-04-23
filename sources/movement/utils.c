/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:31:12 by trolland          #+#    #+#             */
/*   Updated: 2025/04/18 16:11:33 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movement.h"

int	is_walkable(t_data *infos, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0 || map_x >= infos->map_width || map_y < 0
		|| map_y >= infos->map_height)
		return (0);
	if (infos->map[map_y][map_x] == '1' || infos->map[map_y][map_x] == '2')
		return (0);
	return (1);
}
