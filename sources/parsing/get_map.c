/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:45:05 by acaetano          #+#    #+#             */
/*   Updated: 2025/04/21 15:47:31 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static bool	is_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (!str[i])
		return (true);
	return (false);
}

static int	is_mapchr(int c)
{
	if (is_floor_wall(c) || c == ' ' || c == '\n' || is_player(c))
		return (c);
	return (0);
}

static bool	is_map(char *str)
{
	int	i;

	i = 0;
	while (str[i] && is_mapchr(str[i]))
		i++;
	if (!str[i])
		return (true);
	return (false);
}

void	get_map_size(t_data *infos)
{
	int	i;
	int	j;

	i = 0;
	while (infos->map[i])
	{
		j = 0;
		while (infos->map[i][j])
			j++;
		if (j > infos->map_width)
			infos->map_width = ft_max(infos->map_width, j);
		i++;
	}
	infos->map_height = i;
}

char	**get_map(char **file, t_player *player, t_data *infos)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (is_empty(file[i]))
			i++;
		else if (is_map(file[i]) || !is_element(file[i]))
			break ;
		else
			i++;
	}
	if (!is_map_valid(&file[i], player, infos))
		return (ft_dprintf(STDERR_FILENO, "Error: cub3d: Invalid map\n"), NULL);
	return (&file[i]);
}
