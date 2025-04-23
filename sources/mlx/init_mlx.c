/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:15:40 by acaetano          #+#    #+#             */
/*   Updated: 2025/04/18 19:32:07 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movement.h"

void	my_mlx_pixel_put(t_data *infos, int x, int y, int color)
{
	char	*dst;
	t_mlx	*mlx;

	mlx = &infos->display;
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = mlx->addr + (y * mlx->l_ln + (x * (mlx->b_ppl / 8)));
		*(unsigned int *)dst = color;
	}
}

void	init_mlx(t_data *infos)
{
	t_mlx	*mlx;

	mlx = &infos->display;
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		ft_exit_error(infos);
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "cub3d");
	if (!mlx->win)
		ft_exit_error(infos);
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	if (!mlx->img)
		ft_exit_error(infos);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->b_ppl, &mlx->l_ln, &mlx->end);
	if (!mlx->addr)
		ft_exit_error(infos);
	if (!set_textures(infos))
		ft_exit_error(infos);
	mlx_do_key_autorepeatoff(mlx->mlx);
	mlx_hook(mlx->win, 2, (1L << 0), handle_key_press, infos);
	mlx_hook(mlx->win, 3, (1L << 1), handle_key_release, infos);
	mlx_hook(mlx->win, 6, (1L << 6), mouse_motion_hook, infos);
	mlx_loop_hook(mlx->mlx, game_loop, infos);
	mlx_hook(mlx->win, 17, 0, ft_close, infos);
	mlx_loop(mlx->mlx);
}
