/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:00:44 by acaetano          #+#    #+#             */
/*   Updated: 2025/04/21 11:23:30 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	ft_protect(t_data *infos)
{
	if (infos->file)
		ft_freetab(infos->file);
	if (infos->textures_paths)
		ft_freetab(infos->textures_paths);
	exit(EXIT_FAILURE);
}

void	get_data(t_data *infos, char *path)
{
	infos->file = get_file(path);
	if (!infos->file)
		ft_protect(infos);
	infos->textures_paths = get_textures_paths(infos->file, infos);
	if (!infos->textures_paths)
		ft_protect(infos);
	infos->c_color = set_color("C", infos->file);
	if (infos->c_color < 0)
		ft_protect(infos);
	infos->f_color = set_color("F", infos->file);
	if (infos->f_color < 0)
		ft_protect(infos);
	infos->map = get_map(infos->file, &infos->player, infos);
	if (!infos->map)
		ft_protect(infos);
	get_map_size(infos);
}
