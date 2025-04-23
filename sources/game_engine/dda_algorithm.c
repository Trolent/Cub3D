/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:33:20 by acaetano          #+#    #+#             */
/*   Updated: 2025/04/19 16:00:27 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_engine.h"

static void	init_delta_dist(t_dda *d)
{
	if (d->ray_dir_x == 0)
		d->delta_dist_x = INFINITY;
	else
		d->delta_dist_x = fabs(1.0 / d->ray_dir_x);
	if (d->ray_dir_y == 0)
		d->delta_dist_y = INFINITY;
	else
		d->delta_dist_y = fabs(1.0 / d->ray_dir_y);
}

static void	init_step(t_data *infos, t_dda *d)
{
	if (d->ray_dir_x < 0)
	{
		d->step_x = -1;
		d->side_dist_x = (infos->player.pos_x - d->map_x) * d->delta_dist_x;
	}
	else
	{
		d->step_x = 1;
		d->side_dist_x = (d->map_x + 1.0 - infos->player.pos_x);
		d->side_dist_x *= d->delta_dist_x;
	}
	if (d->ray_dir_y < 0)
	{
		d->step_y = -1;
		d->side_dist_y = (infos->player.pos_y - d->map_y) * d->delta_dist_y;
	}
	else
	{
		d->step_y = 1;
		d->side_dist_y = (d->map_y + 1.0 - infos->player.pos_y);
		d->side_dist_y *= d->delta_dist_y;
	}
}

static void	init_vars(t_data *infos, t_ray *ray, t_dda *d)
{
	d->ray_dir_x = cos(ray->angle * M_PI / 180.0);
	d->ray_dir_y = sin(ray->angle * M_PI / 180.0);
	cosinta(infos, d);
	d->map_x = infos->player.pos_x;
	d->map_y = infos->player.pos_y;
	init_delta_dist(d);
	init_step(infos, d);
}

static void	perform_dda_algo(t_data *infos, t_ray *ray, t_dda *d, int *hit)
{
	if (d->side_dist_x < d->side_dist_y)
	{
		d->side_dist_x += d->delta_dist_x;
		d->map_x += d->step_x;
		ray->side = 0;
	}
	else
	{
		d->side_dist_y += d->delta_dist_y;
		d->map_y += d->step_y;
		ray->side = 1;
	}
	if (d->map_x >= 0 && d->map_y >= 0 && d->map_y < infos->map_height
		&& (size_t)d->map_x < ft_strlen(infos->map[d->map_y]))
	{
		if (infos->map[d->map_y][d->map_x] == '1')
			*hit = 1;
		else if (infos->map[d->map_y][d->map_x] == '2')
		{
			ray->door = true;
			*hit = 1;
		}
	}
	else
		*hit = 1;
}

double	calculate_dda_distance(t_data *infos, t_ray *ray)
{
	t_dda	d;
	int		hit;
	double	perp_wall_dist;

	hit = 0;
	init_vars(infos, ray, &d);
	while (!hit)
		perform_dda_algo(infos, ray, &d, &hit);
	if (ray->side == 0)
		perp_wall_dist = d.side_dist_x - d.delta_dist_x;
	else
		perp_wall_dist = d.side_dist_y - d.delta_dist_y;
	if (perp_wall_dist < 0.0001)
		perp_wall_dist = 0.0001;
	return (perp_wall_dist);
}
