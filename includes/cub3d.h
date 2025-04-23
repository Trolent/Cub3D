/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:39:39 by acaetano          #+#    #+#             */
/*   Updated: 2025/04/21 11:22:32 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "ft_dprintf.h"
# include "libft.h"
# include "typedef.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <sys/time.h>
# if defined(__linux__)
#  include "../dependencies/minilibx/minilibx-linux/mlx.h"
# elif defined(__APPLE__)
#  include "../dependencies/minilibx/minilibx_macos/mlx.h"
# endif

# define MOVE_SPEED 0.1

/* ************************************************************************** */
/*                              ERROR_MANAGEMENT                              */
/* ************************************************************************** */

void	check_arguments(int argc, char *path);
void	get_data(t_data *infos, char *path);
bool	set_textures(t_data *infos);

/* ************************************************************************** */
/*                                DISPLAY_MLX                                 */
/* ************************************************************************** */

int		game_loop(t_data *infos);
void	init_mlx(t_data *infos);
void	my_mlx_pixel_put(t_data *infos, int x, int y, int color);

/* ************************************************************************** */
/*                                 KEY_HOOKS                                  */
/* ************************************************************************** */

int		key_hook(t_data *infos);
int		handle_key_release(int keycode, t_data *data);
int		handle_key_press(int keycode, t_data *data);
int		mouse_motion_hook(int x, int y, t_data *infos);

/* ************************************************************************** */
/*                               MISCELLANEOUS                                */
/* ************************************************************************** */

void	ft_exit(t_data *infos);
void	ft_exit_error(t_data *infos);
int		ft_close(t_data *infos);
void	print_map(t_data *infos);

/* ************************************************************************** */
/*                                  KEY_HOOK                                  */
/* ************************************************************************** */

void	set_north(double *degrees);
void	set_south(double *degrees);
void	set_east(double *degrees);
void	set_west(double *degrees);
int		key_dir(int keycode);

#endif
