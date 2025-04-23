/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forward.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:37:31 by acaetano          #+#    #+#             */
/*   Updated: 2025/04/16 22:23:23 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movement.h"

void	ft_forward(t_data *infos)
{
	double	move_step_x;
	double	move_step_y;
	double	new_x;
	double	new_y;

	move_step_x = cos(infos->player.degrees * M_PI / 180.0) * MOVE_SPEED;
	move_step_y = sin(infos->player.degrees * M_PI / 180.0) * MOVE_SPEED;
	new_x = infos->player.pos_x + move_step_x;
	new_y = infos->player.pos_y + move_step_y;
	if (is_walkable(infos, new_x, infos->player.pos_y))
		infos->player.pos_x = new_x;
	if (is_walkable(infos, infos->player.pos_x, new_y))
		infos->player.pos_y = new_y;
}

void	ft_forward_rleft(t_data *infos)
{
	double	move_step_x;
	double	move_step_y;
	double	new_x;
	double	new_y;

	move_step_x = cos(infos->player.degrees * M_PI / 180.0) * MOVE_SPEED;
	move_step_y = sin(infos->player.degrees * M_PI / 180.0) * MOVE_SPEED;
	new_x = infos->player.pos_x + move_step_x;
	new_y = infos->player.pos_y + move_step_y;
	if (is_walkable(infos, new_x, infos->player.pos_y))
	{
		infos->player.pos_x = new_x;
	}
	if (is_walkable(infos, infos->player.pos_x, new_y))
	{
		infos->player.pos_y = new_y;
	}
	ft_turn_left(infos);
}

void	ft_forward_rright(t_data *infos)
{
	double	move_step_x;
	double	move_step_y;
	double	new_x;
	double	new_y;

	move_step_x = cos(infos->player.degrees * M_PI / 180.0) * MOVE_SPEED;
	move_step_y = sin(infos->player.degrees * M_PI / 180.0) * MOVE_SPEED;
	new_x = infos->player.pos_x + move_step_x;
	new_y = infos->player.pos_y + move_step_y;
	if (is_walkable(infos, new_x, infos->player.pos_y))
	{
		infos->player.pos_x = new_x;
	}
	if (is_walkable(infos, infos->player.pos_x, new_y))
	{
		infos->player.pos_y = new_y;
	}
	ft_turn_right(infos);
}
