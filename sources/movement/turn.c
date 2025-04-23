/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:27:38 by trolland          #+#    #+#             */
/*   Updated: 2025/04/18 14:40:58 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movement.h"

void	ft_turn_left(t_data *infos)
{
	infos->player.degrees -= 2;
}

void	ft_turn_right(t_data *infos)
{
	infos->player.degrees += 2;
}
