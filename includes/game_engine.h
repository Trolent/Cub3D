/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_engine.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:45:29 by trolland          #+#    #+#             */
/*   Updated: 2025/04/19 15:54:32 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_ENGINE_H
# define GAME_ENGINE_H

# include "cub3d.h"

typedef struct s_ray
{
	double	angle;
	double	perp_wall_dist;
	int		side;
	bool	door;
}			t_ray;

typedef struct s_wall
{
	double	height;
	double	top;
	double	bottom;
	double	delta_x;
	double	delta_y;
	int		texture;
	double	wall_x;
	double	tex_x;
	double	tex_y;
	double	tex_pos;
}			t_wall;

typedef struct s_dda
{
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		hit;
}			t_dda;

double		calculate_dda_distance(t_data *infos, t_ray *ray);
void		draw_wall_slice(t_data *infos, int screen_x, t_ray *ray);
int			get_tex_color(t_data *infos, int tex, int tex_x, int tex_y);
void		cosinta(t_data *infos, t_dda *d);

#endif
