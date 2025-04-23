/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:37:31 by acaetano          #+#    #+#             */
/*   Updated: 2025/04/21 11:23:21 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	infos;

	ft_bzero(&infos, sizeof(t_data));
	ft_bzero(&infos.display, sizeof(t_mlx));
	ft_bzero(&infos.xpm, sizeof(t_xpm) * 4);
	check_arguments(argc, argv[1]);
	get_data(&infos, argv[1]);
	init_mlx(&infos);
	return (0);
}
