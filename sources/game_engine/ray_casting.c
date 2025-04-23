/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:09:06 by acaetano          #+#    #+#             */
/*   Updated: 2025/04/19 16:53:34 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_engine.h"

static void	ray_casting(t_data *infos)
{
	t_ray	ray;
	int		screen_x;
	double	plane_x;
	double	proj_plane;

	screen_x = 0;
	proj_plane = 6 * tan(FOV / 2.0) * 2;
	ray.door = false;
	while (screen_x < WIDTH)
	{
		plane_x = ((screen_x * 2) - (WIDTH - 1)) / (WIDTH - 1);
		plane_x *= (proj_plane / 2);
		ray.angle = atan2(plane_x, 6) * 180 / M_PI + infos->player.degrees;
		ray.angle = fmod(ray.angle, 360);
		ray.perp_wall_dist = calculate_dda_distance(infos, &ray);
		draw_wall_slice(infos, screen_x, &ray);
		screen_x++;
	}
	mlx_put_image_to_window(infos->display.mlx, infos->display.win,
		infos->display.img, 0, 0);
	print_map(infos);
}

/*
	static struct timeval	last_time = {0};
	struct timeval			current_time;
	double					last_time_sec;
	double					current_time_sec;

	gettimeofday(&current_time, NULL);
	current_time_sec = current_time.tv_sec + current_time.tv_usec / 1000000.0;
	if (last_time.tv_sec == 0)
	{
		last_time = current_time;
		last_time_sec = current_time_sec;
		infos->delta_time = 0;
	}
	else
	{
		last_time_sec = last_time.tv_sec + last_time.tv_usec / 1000000.0;
		infos->delta_time = current_time_sec - last_time_sec;
	}
	last_time = current_time;*/

int	game_loop(t_data *infos)
{
	if (infos->delta_time > 0.1)
		infos->delta_time = 0.1;
	if (infos->delta_time < 0.0)
		infos->delta_time = 0.0;
	key_hook(infos);
	ray_casting(infos);
	mlx_put_image_to_window(infos->display.mlx, infos->display.win,
		infos->display.img, 0, 0);
	return (0);
}
