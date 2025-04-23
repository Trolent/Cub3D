/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:28:56 by trolland          #+#    #+#             */
/*   Updated: 2025/04/21 16:53:37 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

int	enlight_color(int hexColor)
{
	int	r;
	int	g;
	int	b;

	r = (hexColor >> 16) & 0xFF;
	g = (hexColor >> 8) & 0xFF;
	b = hexColor & 0xFF;
	r = r / 0.2;
	g = g / 0.2;
	b = b / 0.2;
	return ((r << 16) | (g << 8) | b);
}

int	is_block(char a, char b, char c)
{
	if (a == b || a == c)
		return (1);
	return (0);
}

int	size_value(void)
{
	static int	size;

	if (size == 0)
		size = (MAP_RADIUS * 2 + 1) * TILE_SIZE;
	return (size);
}

void	draw_map_background(t_data *infos, t_minimap *minimap)
{
	int	i;
	int	j;

	i = 0;
	while (i < minimap->size)
	{
		j = 0;
		while (j < minimap->size)
		{
			my_mlx_pixel_put(infos, j, i, BACKGROUND);
			j++;
		}
		i++;
	}
}

void	draw_map_window(t_data *infos, t_minimap *minimap)
{
	int	i;
	int	j;

	i = 0;
	while (i <= minimap->size)
	{
		j = 0;
		while (j <= minimap->size)
		{
			if (i == 0 || i == minimap->size || j == 0 || j == minimap->size)
				my_mlx_pixel_put(infos, j, i, FRAME);
			else if (i == 1 || i == minimap->size - 1 || j == 1
				|| j == minimap->size - 1)
				my_mlx_pixel_put(infos, j, i, FRAME);
			else if (i == 2 || i == minimap->size - 2 || j == 2
				|| j == minimap->size - 2)
				my_mlx_pixel_put(infos, j, i, FRAME);
			j++;
		}
		i++;
	}
}
