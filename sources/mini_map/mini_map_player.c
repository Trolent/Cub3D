/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:27:24 by trolland          #+#    #+#             */
/*   Updated: 2025/04/18 15:56:02 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"
#include <math.h>

static int	is_point_in_triangle(int *p, t_player_triangle *triangle)
{
	int	d[3];
	int	has_neg;
	int	has_pos;

	d[0] = (p[X] - triangle->y2) * (triangle->x1 - triangle->x2) - (triangle->y1
			- triangle->y2) * (p[Y] - triangle->x2);
	d[1] = (p[X] - triangle->y3) * (triangle->x2 - triangle->x3) - (triangle->y2
			- triangle->y3) * (p[Y] - triangle->x3);
	d[2] = (p[X] - triangle->y1) * (triangle->x3 - triangle->x1) - (triangle->y3
			- triangle->y1) * (p[Y] - triangle->x1);
	has_neg = ((d[0] < 0) || (d[1] < 0) || (d[2] < 0));
	has_pos = ((d[0] > 0) || (d[1] > 0) || (d[2] > 0));
	return (!(has_neg && has_pos));
}

static void	draw_filled_triangle(t_data *infos, t_player_triangle *triangle)
{
	int	min[2];
	int	max[2];
	int	p[2];

	min[X] = fmin(fmin(triangle->x1, triangle->x2), triangle->x3);
	max[X] = fmax(fmax(triangle->x1, triangle->x2), triangle->x3);
	min[Y] = fmin(fmin(triangle->y1, triangle->y2), triangle->y3);
	max[Y] = fmax(fmax(triangle->y1, triangle->y2), triangle->y3);
	p[X] = min[Y] - 1;
	while (++p[X] <= max[Y])
	{
		p[Y] = min[X] - 1;
		while (++p[Y] <= max[X])
			if (is_point_in_triangle(p, triangle))
				my_mlx_pixel_put(infos, p[Y], p[X], 0xFF0000);
	}
}

void	draw_player(t_data *infos, t_minimap *minimap)
{
	int					player_[2];
	double				radian_angle;
	t_player_triangle	triangle;
	double				two_pi_rad;

	two_pi_rad = M_PI * 2 / 3;
	player_[X] = minimap->size / 2;
	player_[Y] = minimap->size / 2;
	radian_angle = infos->player.degrees * (M_PI / 180);
	triangle.x1 = player_[X] + TILE_SIZE * cos(radian_angle);
	triangle.y1 = player_[Y] + TILE_SIZE * sin(radian_angle);
	triangle.x2 = player_[X] + TILE_SIZE * cos(radian_angle + two_pi_rad);
	triangle.y2 = player_[Y] + TILE_SIZE * sin(radian_angle + two_pi_rad);
	triangle.x3 = player_[X] + TILE_SIZE * cos(radian_angle - two_pi_rad);
	triangle.y3 = player_[Y] + TILE_SIZE * sin(radian_angle - two_pi_rad);
	draw_filled_triangle(infos, &triangle);
}
