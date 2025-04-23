/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:12:09 by acaetano          #+#    #+#             */
/*   Updated: 2025/04/18 21:27:28 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	destroy_img_tab(void *mlx, t_xpm **xpm, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		mlx_destroy_image(mlx, xpm[i]->img);
		free(xpm[i]);
		i++;
	}
	free(xpm[i]);
}

bool	set_textures(t_data *infos)
{
	int		i;
	char	*path;
	t_xpm	**xpm;

	i = 0;
	xpm = infos->xpm;
	while (infos->textures_paths[i])
	{
		path = infos->textures_paths[i];
		xpm[i] = ft_calloc(sizeof(t_xpm), 1);
		xpm[i]->img = mlx_xpm_file_to_image(infos->display.mlx, path,
				&xpm[i]->width, &xpm[i]->height);
		if (!xpm[i]->img)
			return (destroy_img_tab(infos->display.mlx, xpm, i), false);
		i++;
	}
	return (true);
}
