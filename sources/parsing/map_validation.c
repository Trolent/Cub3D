/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:42:36 by acaetano          #+#    #+#             */
/*   Updated: 2025/04/21 11:29:14 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static bool	is_valid(char c)
{
	if (!is_player(c) && !is_floor_wall(c) && !is_door(c)
		&& c != ' ' && c != '\n')
		return (false);
	return (true);
}

static bool	check_errors(char **map, t_player *player)
{
	int			i;
	int			j;
	static int	count;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!is_valid(map[i][j]) || (map[i][j] == '\n' && j == 0))
				return (false);
			if (is_player(map[i][j]))
			{
				count += 1;
				player = set_player(player, i, j, map[i][j]);
			}
			if (count > 1)
				return (false);
			j++;
		}
		i++;
	}
	return (count == 1);
}

static bool	is_neighbour(char c)
{
	if (!is_player(c) && c != '0' && c != '1'
		&& c != 'F' && !is_door(c))
		return (false);
	return (true);
}

/*
void	print_array_clear(char **array) {
	int			i;
	static int	prev_count = 0;

	i = 0;
	usleep(50000);
	for (int j = 0; j < prev_count; j++)
	{
		printf("\033[K"); // clear line
		printf("\033[F"); // move cursor up
	}
	printf("\033[K"); // clear line
	while (array[i])
		printf("%s", array[i++]);
	fflush(stdout);
	prev_count = i;
}
*/

static bool	is_valid_neighbour(char **map, int y, int x)
{
	if (!map[y + 1] || (map[y + 1] && x >= (int)ft_strlen(map[y + 1]))
		|| !is_neighbour(map[y + 1][x]))
		return (false);
	else if ((y - 1) < 0 || !map[y - 1] || (map[y - 1]
			&& x >= (int)ft_strlen(map[y - 1])) || !is_neighbour(map[y - 1][x]))
		return (false);
	else if ((x - 1) < 0 || !is_neighbour(map[y][x - 1]))
		return (false);
	else if (!is_neighbour(map[y][x + 1]))
		return (false);
	else if (map[y][x] == '0')
		map[y][x] = 'F';
	return (true);
}

bool	is_map_valid(char **map, t_player *player, t_data *infos)
{
	int	i;
	int	j;

	i = 0;
	if (!check_errors(map, player))
		return (false);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || is_player(map[i][j]) || is_door(map[i][j]))
			{
				if (is_door(map[i][j]) && infos->door == false)
					return (false);
				if (!is_valid_neighbour(map, i, j))
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}
