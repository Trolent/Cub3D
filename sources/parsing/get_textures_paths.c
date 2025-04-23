/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures_paths.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:49:54 by acaetano          #+#    #+#             */
/*   Updated: 2025/04/21 15:52:05 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static const char	*directions(int i)
{
	const char	*directions[] = {
		"NO",
		"SO",
		"EA",
		"WE",
		"DO",
		NULL,
	};

	return (directions[i]);
}

static char	**ft_protect(t_data *infos, char **paths, int size)
{
	int	i;
	int	fd;
	int	tmp_fd;
	int	to_get;

	i = 0;
	fd = STDERR_FILENO;
	if (infos->door)
		to_get = 5;
	else
		to_get = 4;
	if (size != to_get)
	{
		ft_dprintf(fd, "Error:\ncub3d: missing %s texture\n", directions(size));
		return (ft_freetab(paths), NULL);
	}
	while (paths[i])
	{
		tmp_fd = open(paths[i], O_RDONLY);
		if (tmp_fd == -1)
			return (perror("Error:\ncub3d"), ft_freetab(paths), NULL);
		close(tmp_fd);
		i++;
	}
	return (paths);
}

static char	*get_path(char **tab, size_t *i)
{
	int		k;
	char	*path;

	*i = 0;
	k = 0;
	if (tab[k + 1])
		k++;
	path = ft_strdup(tab[k]);
	if (!path)
		return (NULL);
	return (path);
}

int	check_door_path(t_data *infos, char **file)
{
	int	i;
	int	j;
	int	ret;

	ret = DIRECTIONS;
	i = 0;
	while (file[i])
	{
		j = 0;
		while (file[i][j] && ft_isspace(file[i][j]))
			j++;
		if (ft_strncmp(file[i] + j, "DO", 2) == 0)
		{
			if (ft_isspace(file[i][j + 2]))
			{
				infos->door = true;
				ret++;
				break ;
			}
		}
		i++;
	}
	if (ret != DIRECTIONS + 1)
		return (DIRECTIONS);
	return (DIRECTIONS + 1);
}

char	**get_textures_paths(char **file, t_data *infos)
{
	size_t	i;
	int		j;
	char	**paths;
	char	**tmp;

	i = 0;
	j = 0;
	paths = ft_calloc(sizeof(char *), (door_text(infos, file) + 1));
	while (paths && j < door_text(infos, file) && file[i] && directions(j))
	{
		tmp = ft_split(file[i], " \f\r\n\t\v");
		if (!tmp)
			return (ft_freetab(paths), NULL);
		else if (tmp[0] && !ft_strcmp(tmp[0], directions(j)))
		{
			paths[j] = get_path(tmp, &i);
			if (!paths[j] || !check_file_extension(paths[j++], ".xpm"))
				return (ft_error(paths, tmp), NULL);
		}
		else
			i++;
		ft_freetab(tmp);
	}
	paths = ft_protect(infos, paths, j);
	return (paths);
}
