/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_cone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:04:45 by trolland          #+#    #+#             */
/*   Updated: 2025/04/21 16:54:24 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"
#include <math.h>

static int	fade_color(int base_color, double distance)
{
	int	base[3];
	int	bg[3];
	int	faded[3];

	if (distance < 0)
		distance = 0;
	if (distance > 1)
		distance = 1;
	base[R] = (base_color >> 16) & 0xFF;
	base[G] = (base_color >> 8) & 0xFF;
	base[B] = base_color & 0xFF;
	bg[R] = (BACKGROUND >> 16) & 0xFF;
	bg[G] = (BACKGROUND >> 8) & 0xFF;
	bg[B] = BACKGROUND & 0xFF;
	faded[R] = (int)(base[R] * (1 - distance) + bg[R] * distance);
	faded[G] = (int)(base[G] * (1 - distance) + bg[G] * distance);
	faded[B] = (int)(base[B] * (1 - distance) + bg[B] * distance);
	return ((faded[R] << 16) | (faded[G] << 8) | faded[B]);
}

static int	cone_hit(t_data *infos, t_cone *cone)
{
	if (is_block(infos->map[(int)cone->y][(int)cone->x], '1', '2'))
		return (1);
	else if (is_block(infos->map[(int)cone->y][(int)(cone->x
			+ infos->precomputed_cos[cone->segment] * 0.1)], '1', '2')
		&& is_block(infos->map[(int)(cone->y +
				infos->precomputed_sin[cone->segment]
			* 0.1)][(int)cone->x], '1', '2'))
		return (1);
	return (0);
}

static void	draw_line_view(t_data *infos, t_minimap *minimap, double *distance,
		t_cone *cone)
{
	while (cone->x >= 0 && cone->x < infos->map_width && cone->y >= 0
		&& cone->y < infos->map_height)
	{
		if (cone_hit(infos, cone))
			break ;
		cone->mini_map_x = (cone->x - infos->player.pos_x) * TILE_SIZE
			+ (minimap->size / 2);
		cone->mini_map_y = (cone->y - infos->player.pos_y) * TILE_SIZE
			+ (minimap->size / 2);
		if (cone->mini_map_x >= 0 && cone->mini_map_x < minimap->size
			&& cone->mini_map_y >= 0 && cone->mini_map_y < minimap->size)
			my_mlx_pixel_put(infos, cone->mini_map_x, cone->mini_map_y,
				fade_color(0x00FFF0, *distance / CONE_DIST_MAX));
		cone->x += infos->precomputed_cos[cone->segment] * 0.1;
		cone->y += infos->precomputed_sin[cone->segment] * 0.1;
		*distance += 1;
		if (*distance > CONE_DIST_MAX)
			break ;
	}
}

static void	init_cone(t_cone *cone)
{
	cone->x = 0;
	cone->y = 0;
	cone->distance = 0;
	cone->mini_map_x = 0;
	cone->mini_map_y = 0;
	cone->segment = 0;
}

void	draw_cone(t_data *infos, t_minimap *minimap)
{
	double	distance;

	init_cone(&minimap->cone);
	minimap->cone.segment = 0;
	while (minimap->cone.segment < WIDTH)
	{
		minimap->cone.x = infos->player.pos_x;
		minimap->cone.y = infos->player.pos_y;
		distance = 0;
		draw_line_view(infos, minimap, &distance, &minimap->cone);
		minimap->cone.segment += 10;
	}
}
