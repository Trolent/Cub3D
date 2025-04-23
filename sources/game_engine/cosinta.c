/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cosinta.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:49:24 by acaetano          #+#    #+#             */
/*   Updated: 2025/04/19 15:54:05 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_engine.h"

void	cosinta(t_data *infos, t_dda *d)
{
	static int	i;

	if (i == WIDTH)
		i = 0;
	infos->precomputed_cos[i] = d->ray_dir_x;
	infos->precomputed_sin[i] = d->ray_dir_y;
	i++;
}
