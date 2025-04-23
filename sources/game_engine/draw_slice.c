/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_slice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:22:10 by acaetano          #+#    #+#             */
/*   Updated: 2025/04/19 16:51:37 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_engine.h"

static void	init_wall_2(t_wall *wall, t_ray *ray)
{
	if (ray->door == true)
	{
		wall->texture = 4;
		return ;
	}
	if (ray->side == 0)
	{
		if (wall->delta_x > 0)
			wall->texture = 2;
		else
			wall->texture = 3;
	}
	else
	{
		if (wall->delta_y < 0)
			wall->texture = 0;
		else
			wall->texture = 1;
	}
}

static void	init_wall(t_data *infos, t_wall *wall, t_ray *ray, int screen_x)
{
	wall->height = HEIGHT / (ray->perp_wall_dist * cos((ray->angle
					- infos->player.degrees) * M_PI / 180.0));
	wall->top = (HEIGHT - wall->height) / 2.0;
	wall->bottom = (HEIGHT + wall->height) / 2.0;
	wall->delta_x = infos->precomputed_cos[screen_x];
	wall->delta_y = infos->precomputed_sin[screen_x];
	init_wall_2(wall, ray);
	if (ray->side == 0)
		wall->wall_x = infos->player.pos_y + ray->perp_wall_dist
			* wall->delta_y;
	else
		wall->wall_x = infos->player.pos_x + ray->perp_wall_dist
			* wall->delta_x;
	wall->wall_x -= floor(wall->wall_x);
	wall->tex_x = wall->wall_x * infos->xpm[wall->texture]->width;
}

static void	draw_slice_utils(t_data *infos, t_wall wall)
{
	if (wall.tex_y < 0)
		wall.tex_y = 0;
	if (wall.tex_y >= infos->xpm[wall.texture]->height)
		wall.tex_y = infos->xpm[wall.texture]->height - 1;
	if (wall.tex_x < 0)
		wall.tex_x = 0;
	if (wall.tex_x >= infos->xpm[wall.texture]->width)
		wall.tex_x = infos->xpm[wall.texture]->width - 1;
}

static void	draw_slice(t_data *infos, t_ray *ray, t_wall wall, int screen_x)
{
	int	color;
	int	screen_y;

	color = 0;
	screen_y = 0;
	while (screen_y < HEIGHT)
	{
		ray->door = false;
		if (screen_y < wall.top)
			color = infos->c_color;
		else if (screen_y <= wall.bottom)
		{
			wall.tex_pos = (screen_y - wall.top) / wall.height;
			wall.tex_y = wall.tex_pos * infos->xpm[wall.texture]->height;
			draw_slice_utils(infos, wall);
			color = get_tex_color(infos, wall.texture, wall.tex_x, wall.tex_y);
			if (ray->side == 1)
				color = (color >> 1) & 8355711;
		}
		else
			color = infos->f_color;
		my_mlx_pixel_put(infos, screen_x, screen_y, color);
		screen_y++;
	}
}

void	draw_wall_slice(t_data *infos, int screen_x, t_ray *ray)
{
	t_wall	wall;

	init_wall(infos, &wall, ray, screen_x);
	if (ray->side == 0 && wall.delta_x < 0)
		wall.tex_x = infos->xpm[wall.texture]->width - wall.tex_x - 1;
	if (ray->side == 1 && wall.delta_y > 0)
		wall.tex_x = infos->xpm[wall.texture]->width - wall.tex_x - 1;
	draw_slice(infos, ray, wall, screen_x);
}
