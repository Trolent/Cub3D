/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:22:30 by acaetano          #+#    #+#             */
/*   Updated: 2025/04/21 15:51:34 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	array_to_rgb(char **rgb)
{
	int				i;
	int				j;
	int				color;
	int				tmp;
	unsigned char	*bytes;

	i = 0;
	j = 2;
	color = 0;
	bytes = (unsigned char *)&color;
	while (rgb[i])
	{
		tmp = ft_atoi(rgb[i++]);
		if (tmp < 0 || tmp > 255)
			return (-1);
		bytes[j--] = tmp;
	}
	return (color);
}

static int	get_color(char **rgb)
{
	int		color;

	color = 0;
	if (ft_tabsize(rgb) != 3)
		return (-1);
	color = array_to_rgb(rgb);
	return (color);
}

int	set_color(char *str, char **file)
{
	int		i;
	int		rgb;
	char	**tmp;

	i = -1;
	rgb = 0;
	tmp = NULL;
	while (file[++i])
	{
		tmp = ft_split(file[i], " ,\n\t");
		if (!tmp)
			return (perror("Error\n"), -1);
		else if (tmp[0] && tmp[1] && !ft_strcmp(tmp[0], str))
		{
			rgb = get_color(&tmp[1]);
			if (rgb < 0)
				return (ft_freetab(tmp), ft_perror(COLOR_INVALID), -1);
			ft_freetab(tmp);
			tmp = NULL;
			return (rgb);
		}
		ft_freetab(tmp);
		tmp = NULL;
	}
	return (ft_perror(COLOR_NOTFIND), -1);
}
