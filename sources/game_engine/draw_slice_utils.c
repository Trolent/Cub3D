/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_slice_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:22:10 by acaetano          #+#    #+#             */
/*   Updated: 2025/04/19 15:51:17 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_engine.h"

int	get_tex_color(t_data *infos, int tex, int tex_x, int tex_y)
{
	char	*tex_addr;
	int		color;
	int		offset;
	int		bpp;

	tex_addr = mlx_get_data_addr(infos->xpm[tex]->img, &infos->xpm[tex]->bpp,
			&infos->xpm[tex]->line_size, &infos->xpm[tex]->endian);
	bpp = infos->xpm[tex]->bpp / 8;
	offset = (tex_y * infos->xpm[tex]->line_size) + (tex_x * bpp);
	if (offset < 0 || offset >= (infos->xpm[tex]->width
			* infos->xpm[tex]->height * bpp))
		return (0);
	color = *(int *)(tex_addr + offset);
	return (color);
}
