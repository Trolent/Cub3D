/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:50:20 by acaetano          #+#    #+#             */
/*   Updated: 2025/04/21 16:10:22 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	ft_protect(char **file, char *line, int fd)
{
	if (fd > 0)
		close(fd);
	get_next_line(GNL_FLUSH);
	ft_freetab(file);
	free(line);
	line = NULL;
}

static bool	comma_routine(char c, bool *comma, int *count)
{
	if (ft_isdigit(c))
		*comma = true;
	else if (c == ',' && *comma == true)
	{
		*comma = false;
		*count += 1;
	}
	else if ((c == ',' && *comma == false) || !ft_isspace(c))
		return (false);
	return (true);
}

static bool	check_color_format(char *str, int element)
{
	int		i;
	bool	comma;
	int		count;

	i = -1;
	comma = true;
	count = 0;
	if (element < 5 || element > 6)
		return (true);
	while (ft_isspace(str[++i]))
		;
	while (str[++i])
	{
		if (!comma_routine(str[i], &comma, &count))
			break ;
	}
	if (count != 2)
		return (false);
	return (true);
}

static bool	check_duplicates(char *str)
{
	int			i;
	int			len;
	char		*tmp;
	static int	count[7];

	i = 0;
	while (str && elements(i))
	{
		len = ft_strlen(str);
		tmp = ft_strnstr(str, elements(i), len);
		if (tmp && ft_isspace(*(tmp + ft_strlen(elements(i)))))
		{
			if (!check_color_format(str, i))
				return (ft_perror(COLOR_FORMAT), false);
			count[i]++;
		}
		if (count[i] > 1)
			return (ft_perror(DUPLICATE), false);
		i++;
	}
	return (true);
}

char	**get_file(char *file_path)
{
	int		fd;
	char	*line;
	char	**file;

	file = NULL;
	line = NULL;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (ft_protect(file, line, fd), NULL);
	while (1)
	{
		line = get_next_line(fd);
		if ((!line && errno == ENOMEM) || !check_duplicates(line))
			return (ft_protect(file, line, fd), NULL);
		else if (!line && errno == 0)
			break ;
		file = ft_tabjoin(file, line);
		if (errno == ENOMEM)
			return (ft_protect(file, line, fd), NULL);
		if (!line)
			break ;
	}
	if (!file)
		ft_dprintf(STDERR_FILENO, "Error\ncub3D: file is empty\n");
	return (close(fd), file);
}
