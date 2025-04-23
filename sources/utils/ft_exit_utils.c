/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:17:38 by acaetano          #+#    #+#             */
/*   Updated: 2025/04/21 11:30:19 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#ifdef LINUX

void	destroy_xpm_path(t_mlx *display, t_data *infos)
{
	int	i;
	int	xpm_size;

	if (infos->door)
		xpm_size = 5;
	else
		xpm_size = 4;
	i = 0;
	while (infos->xpm[i] && i < xpm_size)
	{
		mlx_destroy_image(display->mlx, infos->xpm[i]->img);
		free(infos->xpm[i]);
		i++;
	}
}

int	ft_close(t_data *infos)
{
	t_mlx	*display;

	display = &infos->display;
	ft_freetab(infos->textures_paths);
	ft_freetab(infos->file);
	mlx_do_key_autorepeaton(display->mlx);
	destroy_xpm_path(display, infos);
	if (display->img)
		mlx_destroy_image(display->mlx, display->img);
	if (display->win)
		mlx_destroy_window(display->mlx, display->win);
	if (display->mlx)
	{
		mlx_destroy_display(display->mlx);
		free(display->mlx);
	}
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

void	ft_exit(t_data *infos)
{
	int		i;
	t_mlx	*display;

	i = 0;
	display = &infos->display;
	ft_freetab(infos->textures_paths);
	ft_freetab(infos->file);
	mlx_do_key_autorepeaton(display->mlx);
	destroy_xpm_path(display, infos);
	if (display->img)
		mlx_destroy_image(display->mlx, display->img);
	if (display->win)
		mlx_destroy_window(display->mlx, display->win);
	if (display->mlx)
	{
		mlx_destroy_display(display->mlx);
		free(display->mlx);
	}
	exit(EXIT_SUCCESS);
}

#endif
#ifndef LINUX

int	ft_close(t_data *infos)
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
	return (EXIT_SUCCESS);
}
#endif
