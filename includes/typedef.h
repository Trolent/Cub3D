/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:44:42 by acaetano          #+#    #+#             */
/*   Updated: 2025/04/21 11:22:56 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

# define DIRECTIONS 4
# define FOV 70.0
# define PDIST 6.0
# define TILE_SIZE 10
# define MAP_RADIUS 10

# if defined(__linux__)
#  define WIDTH 1024.0
#  define HEIGHT 768.0
# elif defined(__APPLE__)
#  define WIDTH 1200.0
#  define HEIGHT 900.0
# endif

typedef struct s_key_tracker
{
	bool			esc;
	bool			a;
	bool			left_arrow;
	bool			d;
	bool			right_arrow;
	bool			w;
	bool			up_arrow;
	bool			s;
	bool			down_arrow;
	bool			ctrl;
	bool			e;
	bool			e_processed;
}					t_key_tracker;

typedef enum e_errors
{
	ERR_SUCCESS = 0,
	ERR_ARGUMENTS,
	ERR_FILETYPE,
	ERR_MAPFILE,
}					t_errors;

typedef enum e_dir
{
	NORTH = 'N',
	SOUTH = 'S',
	EAST = 'E',
	WEST = 'W',
}					t_dir;

typedef struct s_player
{
	t_dir			direction;
	double			pos_x;
	double			pos_y;
	double			degrees;
}					t_player;

// Textures storing

typedef struct s_xpm
{
	void			*img;
	int				width;
	int				height;
	int				bpp;
	int				line_size;
	int				endian;
}					t_xpm;

// General purpose mlx structure

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				b_ppl;
	int				l_ln;
	int				end;
	int				offset;
}					t_mlx;

typedef struct s_data
{
	char			**file;
	char			**textures_paths;
	t_xpm			*xpm[5];
	char			**map;
	int				map_width;
	int				map_height;
	int				c_color;
	int				f_color;
	double			delta_time;
	t_player		player;
	t_mlx			display;
	t_key_tracker	keys_down;
	double			precomputed_cos[(int)WIDTH];
	double			precomputed_sin[(int)WIDTH];
	bool			door;
}					t_data;

#endif
