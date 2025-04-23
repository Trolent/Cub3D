/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:25:09 by acaetano          #+#    #+#             */
/*   Updated: 2025/04/18 16:02:10 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_player	*set_player(t_player *player, int i, int j, char dir)
{
	static void	(*f[4])(double *degrees);

	f[0] = set_north;
	f[1] = set_south;
	f[2] = set_east;
	f[3] = set_west;
	player->pos_x = j + 0.5;
	player->pos_y = i + 0.5;
	f[key_dir(dir)](&player->degrees);
	return (player);
}
