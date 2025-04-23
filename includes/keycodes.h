/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 14:13:08 by trolland          #+#    #+#             */
/*   Updated: 2025/04/18 15:48:12 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODES_H
# define KEYCODES_H

# include "cub3d.h"

# if defined(__linux__)
#  include <X11/keysym.h>
#  define ESC_KEY   0xff1b
#  define A_KEY     0x0061
#  define LEFT_KEY  0xff51
#  define D_KEY     0x0064
#  define RIGHT_KEY 0xff53
#  define W_KEY     0x0077
#  define UP_KEY    0xff52
#  define S_KEY     0x0073
#  define DOWN_KEY  0xff54
#  define CTRL		0xffe3
#  define E_KEY	    0x0065
# elif defined(__APPLE__)
#  define ESC_KEY	53
#  define A_KEY	    0
#  define LEFT_KEY	123
#  define D_KEY	    2
#  define RIGHT_KEY	124
#  define W_KEY	    13
#  define UP_KEY	126
#  define S_KEY	    1
#  define DOWN_KEY	125
#  define CTRL		256
#  define E_KEY	    14
# endif

int	key_map(int keycode);
int	key_hook(t_data *infos);

#endif
