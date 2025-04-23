/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:46:10 by acaetano          #+#    #+#             */
/*   Updated: 2025/04/18 21:34:15 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static const char	*error_messages(t_errors errnum)
{
	const char	*messages[] = {
		"success.",
		"Error\ncub3d: invalid arguments.",
		"Error\ncub3d: invalid filetype",
		"Error\ncub3d: invalid .cub file",
	};

	return (messages[errnum]);
}

static void	ft_prexit(t_errors errnum)
{
	ft_dprintf(STDERR_FILENO, "%s\n", error_messages(errnum));
	exit(errnum);
}

void	check_arguments(int argc, char *path)
{
	if (argc != 2)
		ft_prexit(ERR_ARGUMENTS);
	if (!check_file_extension(path, ".cub"))
		ft_prexit(ERR_FILETYPE);
}
