/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 14:05:31 by trolland          #+#    #+#             */
/*   Updated: 2025/02/16 18:04:42 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "map.h"
#include "types.h"

int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	return (fd);
}

char	*skip_to_path(char *line, char *texture)
{
	while (*line == *texture)
	{
		line++;
		texture++;
	}
	while (*line == ' ')
		line++;
	return (line);
}

int	check_texture(char *line, t_map *map, int *texture)
{
	if (*line == '\0' || *line == '\n')
		return (1);
	if (ft_strncmp(line, "NO ", 3) == 0 && map->no == NULL)
		map->no = ft_strdup((skip_to_path(line + 3, "NO ")));
	else if (ft_strncmp(line, "SO ", 3) == 0 && map->so == NULL)
		map->so = ft_strdup((skip_to_path(line + 3, "SO ")));
	else if (ft_strncmp(line, "WE ", 3) == 0 && map->we == NULL)
		map->we = ft_strdup((skip_to_path(line + 3, "WE ")));
	else if (ft_strncmp(line, "EA ", 3) == 0 && map->ea == NULL)
		map->ea = ft_strdup((skip_to_path(line + 3, "EA ")));
	else if (ft_strncmp(line, "F ", 2) == 0 && map->f == NULL)
		map->f = ft_strdup((skip_to_path(line + 2, "F ")));
	else if (ft_strncmp(line, "C ", 2) == 0 && map->c == NULL)
		map->c = ft_strdup((skip_to_path(line + 2, "C ")));
	else
	{
		if (map->no != NULL && map->so != NULL && map->we != NULL
			&& map->ea != NULL && map->f != NULL && map->c != NULL)
			return (*texture = 1, 1);
		else
			return (0);
	}
	return (1);
}

int	check_map(char *line, t_map *map)
{
	t_row	*cur;
	t_row	*tmp;

	if (!line)
		return (0);
	if (*line == '\0')
		return (1);
	if (map->raw == NULL)
	{
		map->raw = (t_row *)malloc(sizeof(t_row));
		if (!map->raw)
			return (0);
		map->raw->map = ft_strdup(line);
		map->raw->next = NULL;
		map->raw->prev = NULL;
	}
	else
	{
		tmp = map->raw;
		while (tmp->next)
			tmp = tmp->next;
		cur = tmp;
		tmp->next = (t_row *)malloc(sizeof(t_row));
		if (!tmp->next)
			return (0);
		tmp->next->map = ft_strdup(line);
		tmp->next->next = NULL;
		tmp->next->prev = cur;
	}
	map->height++;
	map->width = ft_max(map->width, ft_strlen(line));
	return (1);
}

int	wrong_element(char *c)
{
	if (!c)
		return (0);
	if (*c == ' ' || *c == '\0' || ft_iswhitespace(*c))
		return (1);
	return (0);
}

int	valid_element(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

int	around_valid_element(t_row *row, int i)
{
	if (!row->next || !row->prev)
		return (1);
	if (valid_element(row->map[i]))
	{
		if (wrong_element(&row->map[i - 1]) || wrong_element(&row->map[i + 1]))
			return (1);
	}
	return (0);
}

int	player_element(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

int	verify_map(t_map *map)
{
	int		i;
	int 	player;
	t_row	*tmp;

	if (!map || !map->raw)
		return (1);
	tmp = map->raw;
	player = 0;
	while (tmp)
	{
		i = 0;
		while (tmp->map[i])
		{
			if (player_element(tmp->map[i]) && player == 0)
				player++;
			else if (player_element(tmp->map[i]) && player >= 0)
				return (0);
			if ((!tmp->prev || !tmp->next) && tmp->map[i])
			{
				if (tmp->map[i] == '\0')
					break ;
				if (tmp->map[i] != '1' && tmp->map[i] != ' '
					&& tmp->map[i] != '\n')
					return (0);
			}
			else if ((tmp->prev && tmp->next) && tmp->map[i])
			{
				if (tmp->map[i] == '\0')
					break ;
				if (around_valid_element(tmp, i))
					return (0);
			}
			i++;
		}
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
	}
	return (1);
}

int	parse_map(t_map *map, int fd)
{
	char	*ret;
	int		texture;

	ret = NULL;
	texture = 0;
	while (1)
	{
		ret = get_next_line(fd);
		if (ret == 0 || ret == NULL)
			break ;
		if (texture == 0)
			if (!check_texture(ret, map, &texture))
				return (free(ret), 0);
		if (texture == 1)
			if (!check_map(ret, map))
				return (free(ret), 0);
		free(ret);
	}
	if (!verify_map(map))
		return (0);
	return (1);
}

int	set_map(t_map *map, int argc, char **argv)
{
	int fd;

	if (argc != 2)
		return (0);
	if (check_last_characters(argv[1], ".cub") != 1)
		return (0);
	fd = open_file(argv[1]);
	if (fd == 0)
		return (0);
	if (parse_map(map, fd) == 0)
		return (free_map(map), close(fd), 0);
	print_map(map);
	close(fd);
	return (1);
}