/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:03:55 by trolland          #+#    #+#             */
/*   Updated: 2025/04/21 15:52:28 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_perror(t_errno error)
{
	const char	*errors[] = {
		"Error\ncub3D: invalid RGB color",
		"Error\ncub3D: Ceiling or Floor color not found",
		"Error\ncub3D: Found duplicate Texture or Color",
		"Error\ncub3D: Found invalid color format",
	};

	ft_dprintf(STDERR_FILENO, "%s\n", errors[error]);
}

void	ft_error(char **paths, char **tmp)
{
	ft_freetab(paths);
	ft_freetab(tmp);
	ft_dprintf(STDERR_FILENO, "Error\ncub3D : Invalid texture\n");
}
