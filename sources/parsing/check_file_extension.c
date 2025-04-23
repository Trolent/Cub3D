/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_extension.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:07:19 by acaetano          #+#    #+#             */
/*   Updated: 2025/04/18 16:01:26 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	check_file_extension(char *path, char *extension)
{
	size_t	len;

	len = ft_strlen(path);
	if (len <= 4 || ft_strcmp(extension, (path + (len - 4))))
		return (false);
	else
		return (true);
}
