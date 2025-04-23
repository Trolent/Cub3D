/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:17:38 by acaetano          #+#    #+#             */
/*   Updated: 2025/04/19 14:57:39 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#ifdef LINUX

void	ft_exit_error(t_data *infos)
{
	t_mlx	*display;

	display = &infos->display;
	ft_freetab(infos->textures_paths);
	ft_freetab(infos->file);
	if (display->img)
		mlx_destroy_image(display->mlx, display->img);
	if (display->win)
		mlx_destroy_window(display->mlx, display->win);
	if (display->mlx)
	{
		mlx_destroy_display(display->mlx);
		free(display->mlx);
	}
	ft_dprintf(STDERR_FILENO, "Error\ncub3d : could not start mlx\n");
	exit(EXIT_FAILURE);
}

#endif
#ifndef LINUX

void	ft_exit_error(t_data *infos)
{
	t_mlx	*display;

	display = &infos->display;
	ft_freetab(infos->textures_paths);
	ft_freetab(infos->file);
	if (display->mlx)
		free(display->mlx);
	ft_dprintf(STDERR_FILENO, "Error\ncub3d : could not start mlx\n");
	exit(EXIT_FAILURE);
}

void	ft_exit(t_data *infos)
{
	t_mlx	*display;

	display = &infos->display;
	ft_freetab(infos->textures_paths);
	ft_freetab(infos->file);
	if (display->img)
		mlx_destroy_image(display->mlx, display->img);
	if (display->win)
		mlx_destroy_window(display->mlx, display->win);
	if (display->mlx)
		free(display->mlx);
	exit(EXIT_SUCCESS);
}

#endif
