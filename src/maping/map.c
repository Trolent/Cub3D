/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 14:07:29 by trolland          #+#    #+#             */
/*   Updated: 2025/02/16 17:59:59 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "map.h"
#include "types.h"

void print_map(t_map *map)
{
    ft_printf("NO: %s\n", map->no);
    ft_printf("SO: %s\n", map->so);
    ft_printf("WE: %s\n", map->we);
    ft_printf("EA: %s\n", map->ea);
    ft_printf("F: %s\n", map->f);
    ft_printf("C: %s\n", map->c);

    t_row *current = map->raw;
    while (current)
    {
        ft_printf("%s", current->map);
        current = current->next;
    }
}

void	free_rows(t_map *map)
{
	t_row	*row;
	t_row	*tmp;

	row = map->raw;
	while (row)
	{
		tmp = row;
		row = row->next;
		if (tmp->map)
			free(tmp->map);
		free(tmp);
	}
	map->raw = NULL;
}

void	free_map(t_map *map)
{
	if (map->no)
		free(map->no);
	if (map->so)
		free(map->so);
	if (map->we)
		free(map->we);
	if (map->ea)
		free(map->ea);
	if (map->f)
		free(map->f);
	if (map->c)
		free(map->c);
	free_rows(map);
}