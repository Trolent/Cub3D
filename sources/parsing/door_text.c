/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaetano <acaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:37:43 by acaetano          #+#    #+#             */
/*   Updated: 2025/04/21 15:38:45 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	door_text(t_data *infos, char **file)
{
	int		i;
	int		j;
	int		ret;

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
