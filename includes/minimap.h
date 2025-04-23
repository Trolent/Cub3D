/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:38:12 by trolland          #+#    #+#             */
/*   Updated: 2025/04/21 16:53:50 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "cub3d.h"

# define RED 0xff0000
# define GREEN 0x00ff00
# define BLUE 0x0000ff
# define WHITE 0xffffff
# define BLACK 0x000000
# define BACKGROUND 0xada99e
# define FRAME 0xfcba03

# define WALL 0x03c6fc
# define DOOR_CLOSED 0x5A2E1D
# define DOOR_OPEN 0x658f70

# define X 0
# define Y 1

# define R 0
# define G 1
# define B 2

# define TILE_SIZE 10
# define MAP_RADIUS 10

# define CONE_DIST_MAX 100.0

typedef struct s_player_triangle
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		x3;
	int		y3;
}			t_player_triangle;

typedef struct s_cone
{
	double	x;
	double	y;
	double	distance;
	int		mini_map_x;
	int		mini_map_y;
	int		segment;

}			t_cone;

typedef struct s_minimap
{
	int		map_x;
	int		map_y;
	double	offset_x;
	double	offset_y;
	int		diameter;
	int		size;
	t_cone	cone;

}			t_minimap;

void		draw_player(t_data *infos, t_minimap *minimap);
void		draw_cone(t_data *infos, t_minimap *minimap);
int			is_block(char a, char b, char c);
int			size_value(void);
void		draw_map_background(t_data *infos, t_minimap *minimap);
void		draw_map_window(t_data *infos, t_minimap *minimap);
int			enlight_color(int hexColor);

#endif
