/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:29:04 by trolland          #+#    #+#             */
/*   Updated: 2025/04/17 23:43:24 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENT_H
# define MOVEMENT_H

# include "cub3d.h"

# define MOUSE_SENSITIVITY 0.1

int		is_walkable(t_data *infos, double x, double y);

void	ft_turn_left(t_data *infos);
void	ft_turn_right(t_data *infos);

void	ft_forward(t_data *infos);
void	ft_forward_rleft(t_data *infos);
void	ft_forward_rright(t_data *infos);

void	ft_backward(t_data *infos);
void	ft_backward_rleft(t_data *infos);
void	ft_backward_rright(t_data *infos);

void	ft_left(t_data *infos);
void	ft_right(t_data *infos);
void	ft_forward_right(t_data *infos);
void	ft_forward_left(t_data *infos);
void	ft_backward_left(t_data *infos);
void	ft_backward_right(t_data *infos);
void	ft_interact(t_data *infos);
int		door_key(int keycode, t_data *infos);

#endif