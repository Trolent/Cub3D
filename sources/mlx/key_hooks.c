/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:57:39 by acaetano          #+#    #+#             */
/*   Updated: 2025/04/18 19:33:59 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "keycodes.h"
#include "movement.h"

int	key_map(int keycode)
{
	int			i;
	const int	key[11] = {ESC_KEY, A_KEY, LEFT_KEY, D_KEY, RIGHT_KEY, W_KEY,
		UP_KEY, S_KEY, DOWN_KEY, CTRL, E_KEY};

	i = -1;
	while (++i < 11)
		if (keycode == key[i])
			return (i);
	return (-1);
}

int	key_hook2(t_data *infos)
{
	if ((infos->keys_down.s || infos->keys_down.down_arrow)
		&& infos->keys_down.d)
		ft_backward_right(infos);
	else if (infos->keys_down.w || infos->keys_down.up_arrow)
		ft_forward(infos);
	else if (infos->keys_down.s || infos->keys_down.down_arrow)
		ft_backward(infos);
	else if (infos->keys_down.left_arrow)
		ft_turn_left(infos);
	else if (infos->keys_down.right_arrow)
		ft_turn_right(infos);
	else if (infos->keys_down.a)
		ft_left(infos);
	else if (infos->keys_down.d)
		ft_right(infos);
	else if (infos->keys_down.esc)
		ft_exit(infos);
	else if (infos->keys_down.e && !infos->keys_down.e_processed)
	{
		ft_interact(infos);
		infos->keys_down.e_processed = true;
	}
	return (0);
}

int	key_hook(t_data *infos)
{
	if ((infos->keys_down.w || infos->keys_down.up_arrow)
		&& infos->keys_down.left_arrow)
		ft_forward_rleft(infos);
	else if ((infos->keys_down.w || infos->keys_down.up_arrow)
		&& infos->keys_down.right_arrow)
		ft_forward_rright(infos);
	else if ((infos->keys_down.s || infos->keys_down.down_arrow)
		&& infos->keys_down.left_arrow)
		ft_backward_rleft(infos);
	else if ((infos->keys_down.s || infos->keys_down.down_arrow)
		&& infos->keys_down.right_arrow)
		ft_backward_rright(infos);
	else if ((infos->keys_down.w || infos->keys_down.up_arrow)
		&& infos->keys_down.a)
		ft_forward_left(infos);
	else if ((infos->keys_down.w || infos->keys_down.up_arrow)
		&& infos->keys_down.d)
		ft_forward_right(infos);
	else if ((infos->keys_down.s || infos->keys_down.down_arrow)
		&& infos->keys_down.a)
		ft_backward_left(infos);
	else
		key_hook2(infos);
	return (0);
}
