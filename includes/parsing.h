/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:59:06 by trolland          #+#    #+#             */
/*   Updated: 2025/04/21 16:10:52 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"

typedef enum e_errno
{
	COLOR_INVALID,
	COLOR_NOTFIND,
	DUPLICATE,
	COLOR_FORMAT,
}			t_errno;

/* ************************************************************************** */
/*                               MAP_EXTRACTION                               */
/* ************************************************************************** */

bool		check_file_extension(char *path, char *extension);
int			door_text(t_data *infos, char **file);
char		**get_file(char *file_path);
char		**get_textures_paths(char **file, t_data *infos);
int			set_color(char *str, char **file);
t_player	*set_player(t_player *player, int i, int j, char dir);
char		*elements(int i);
bool		is_element(char *str);
char		**get_map(char **file, t_player *player, t_data *infos);
void		get_map_size(t_data *infos);
bool		is_map_valid(char **map, t_player *player, t_data *infos);
int			is_player(char c);
int			is_door(char c);
int			is_floor_wall(char c);

/* ************************************************************************** */
/*                                   ERROR                                    */
/* ************************************************************************** */

char		*elements(int i);
void		ft_perror(t_errno error);
void		ft_error(char **paths, char **tmp);

#endif
