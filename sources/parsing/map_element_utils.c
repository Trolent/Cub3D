/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_element_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:42:36 by acaetano          #+#    #+#             */
/*   Updated: 2025/04/21 11:08:20 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

int	is_door(char c)
{
	if (c == '2' || c == '3')
		return (1);
	return (0);
}

int	is_floor_wall(char c)
{
	if (c == '0' || c == '1')
		return (1);
	return (0);
}
