/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_release.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:57:39 by acaetano          #+#    #+#             */
/*   Updated: 2025/04/18 08:47:33 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keycodes.h"

void	handle_key_press2(int index, t_data *data)
{
	if (index == 9)
		data->keys_down.ctrl = true;
	else if (index == 10)
	{
		data->keys_down.e = true;
		data->keys_down.e_processed = false;
	}
}

int	handle_key_press(int keycode, t_data *data)
{
	int	index;

	index = key_map(keycode);
	if (index > 8)
		handle_key_press2(index, data);
	else if (index == 0)
		data->keys_down.esc = true;
	else if (index == 1)
		data->keys_down.a = true;
	else if (index == 2)
		data->keys_down.left_arrow = true;
	else if (index == 3)
		data->keys_down.d = true;
	else if (index == 4)
		data->keys_down.right_arrow = true;
	else if (index == 5)
		data->keys_down.w = true;
	else if (index == 6)
		data->keys_down.up_arrow = true;
	else if (index == 7)
		data->keys_down.s = true;
	else if (index == 8)
		data->keys_down.down_arrow = true;
	return (0);
}

void	handle_key_release2(int index, t_data *data)
{
	if (index == 9)
		data->keys_down.ctrl = false;
	else if (index == 10)
	{
		data->keys_down.e = false;
		data->keys_down.e_processed = false;
	}
}

int	handle_key_release(int keycode, t_data *data)
{
	int	index;

	index = key_map(keycode);
	if (index > 8)
		handle_key_release2(index, data);
	else if (index == 0)
		data->keys_down.esc = false;
	else if (index == 1)
		data->keys_down.a = false;
	else if (index == 2)
		data->keys_down.left_arrow = false;
	else if (index == 3)
		data->keys_down.d = false;
	else if (index == 4)
		data->keys_down.right_arrow = false;
	else if (index == 5)
		data->keys_down.w = false;
	else if (index == 6)
		data->keys_down.up_arrow = false;
	else if (index == 7)
		data->keys_down.s = false;
	else if (index == 8)
		data->keys_down.down_arrow = false;
	return (0);
}
