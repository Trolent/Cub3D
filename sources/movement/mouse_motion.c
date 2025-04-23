/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_motion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:15:30 by acaetano          #+#    #+#             */
/*   Updated: 2025/04/18 21:39:44 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "movement.h"

#ifdef LINUX

typedef struct s_motion_hook
{
	int	center_x;
	int	delta_x;
}		t_motion_hook;

void	motion_hook_init(t_motion_hook *motion_hook, int x, int y)
{
	(void)y;
	motion_hook->center_x = WIDTH / 2;
	motion_hook->delta_x = x - motion_hook->center_x;
}

void	motion_hook_update(t_motion_hook *motion_hook, t_data *infos)
{
	infos->player.degrees += motion_hook->delta_x * MOUSE_SENSITIVITY;
	if (infos->player.degrees < 0)
		infos->player.degrees += 360.0;
	if (infos->player.degrees >= 360.0)
		infos->player.degrees -= 360.0;
}

void	mouse_motion_move(t_data *infos, t_motion_hook *motion_hook)
{
	if (infos->display.mlx && infos->display.win)
		mlx_mouse_move(infos->display.mlx, infos->display.win,
			motion_hook->center_x, HEIGHT / 2);
}

int	mouse_motion_hook(int x, int y, t_data *infos)
{
	t_motion_hook	motion_hook;
	static int		cursor_hidden = 0;

	motion_hook_init(&motion_hook, x, y);
	if (infos->keys_down.ctrl)
	{
		if (cursor_hidden && infos->display.mlx && infos->display.win)
		{
			mlx_mouse_show(infos->display.mlx, infos->display.win);
			cursor_hidden = 0;
		}
		return (0);
	}
	if (motion_hook.delta_x != 0)
	{
		motion_hook_update(&motion_hook, infos);
		if (!cursor_hidden && infos->display.mlx && infos->display.win)
		{
			mlx_mouse_hide(infos->display.mlx, infos->display.win);
			cursor_hidden = 1;
		}
		mouse_motion_move(infos, &motion_hook);
	}
	return (0);
}
#endif
#ifndef LINUX

int	mouse_motion_hook(int x, int y, t_data *infos)
{
	int	center_x;
	int	delta_x;

	(void)y;
	center_x = WIDTH / 2;
	delta_x = x - center_x;
	if (infos->keys_down.ctrl)
	{
		mlx_mouse_show(infos->display.mlx, infos->display.win);
		return (0);
	}
	else if (delta_x != 0)
	{
		infos->player.degrees += delta_x * MOUSE_SENSITIVITY;
		if (infos->player.degrees < 0)
			infos->player.degrees += 360.0;
		if (infos->player.degrees >= 360.0)
			infos->player.degrees -= 360.0;
		mlx_mouse_hide(infos->display.mlx, infos->display.win);
		mlx_mouse_move(infos->display.win, center_x, HEIGHT / 2);
	}
	return (0);
}
#endif
