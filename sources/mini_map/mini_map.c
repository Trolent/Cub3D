/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:14:04 by trolland          #+#    #+#             */
/*   Updated: 2025/04/18 18:22:58 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

static void	tile_print(t_data *infos, double x, double y, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < TILE_SIZE)
	{
		j = -1;
		while (++j < TILE_SIZE)
		{
			if ((x * TILE_SIZE + j) >= 0 && (x * TILE_SIZE + j) < size_value()
				&& (y * TILE_SIZE + i) >= 0 && (y * TILE_SIZE
					+ i) < size_value())
			{
				if (color != BACKGROUND && (i == 0 || i == TILE_SIZE - 1
						|| j == 0 || j == TILE_SIZE - 1))
					my_mlx_pixel_put(infos, (x * TILE_SIZE + j), (y * TILE_SIZE
							+ i), enlight_color(color));
				else
					my_mlx_pixel_put(infos, (x * TILE_SIZE + j), (y * TILE_SIZE
							+ i), color);
			}
		}
	}
}

static void	obstacle_list(t_data *infos, int i, int j, t_minimap *minimap)
{
	double	x;
	double	y;

	minimap->map_x = ((int)infos->player.pos_x - MAP_RADIUS) + j;
	minimap->map_y = ((int)infos->player.pos_y - MAP_RADIUS) + i;
	x = j - minimap->offset_x + 0.5;
	y = i - minimap->offset_y + 0.5;
	if (minimap->map_y >= 0 && minimap->map_y < infos->map_height
		&& minimap->map_x >= 0 && infos->map[(int)minimap->map_y]
		&& minimap->map_x < (int)ft_strlen(infos->map[(int)minimap->map_y]))
	{
		if (infos->map[(int)minimap->map_y][(int)minimap->map_x] == '1')
			tile_print(infos, x, y, WALL);
		else if (infos->map[(int)minimap->map_y][(int)minimap->map_x] == '0')
			tile_print(infos, x, y, BACKGROUND);
		else if (infos->map[(int)minimap->map_y][(int)minimap->map_x] == '2')
			tile_print(infos, x, y, DOOR_CLOSED);
		else if (infos->map[(int)minimap->map_y][(int)minimap->map_x] == '3')
			tile_print(infos, x, y, DOOR_OPEN);
	}
	else
		tile_print(infos, j + 0.5 - minimap->offset_x, i + 0.5
			- minimap->offset_y, BACKGROUND);
}

static void	draw_obstacle(t_data *infos, t_minimap *minimap)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= minimap->diameter)
	{
		j = -1;
		while (++j <= minimap->diameter)
			obstacle_list(infos, i, j, minimap);
	}
}

static void	set_minimap_values(t_data *infos, t_minimap *minimap)
{
	minimap->offset_x = ft_modf(infos->player.pos_x, NULL);
	minimap->offset_y = ft_modf(infos->player.pos_y, NULL);
	minimap->diameter = MAP_RADIUS * 2 + 1;
	minimap->size = minimap->diameter * TILE_SIZE;
}

void	print_map(t_data *infos)
{
	t_minimap	minimap;

	set_minimap_values(infos, &minimap);
	draw_map_background(infos, &minimap);
	draw_cone(infos, &minimap);
	draw_obstacle(infos, &minimap);
	draw_player(infos, &minimap);
	draw_map_window(infos, &minimap);
}
