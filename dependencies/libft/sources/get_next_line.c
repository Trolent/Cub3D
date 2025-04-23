/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaetano <acaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:26:33 by acaetano          #+#    #+#             */
/*   Updated: 2025/04/18 20:41:56 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clean_node(t_buffer **lst, char *next_line, size_t j)
{
	t_buffer	*new;
	size_t		i;

	i = 0;
	if (!(*lst)->buffer[j + 1])
		return (ft_bufclear(lst));
	new = malloc(sizeof(t_buffer));
	if (!new)
	{
		free(next_line);
		next_line = NULL;
		return (ft_bufclear(lst));
	}
	new->next = NULL;
	j += 1;
	while ((*lst)->buffer[j])
		new->buffer[i++] = (*lst)->buffer[j++];
	new->buffer[i] = 0;
	ft_bufclear(lst);
	*lst = new;
}

t_buffer	*read_to_list(int fd, t_buffer *lst, size_t *len)
{
	size_t		buflen;
	t_buffer	*head;

	head = NULL;
	lst = ft_lstnew_gnl(fd, lst);
	if (!lst)
		return (NULL);
	head = lst;
	buflen = ft_strlen_nl(lst->buffer);
	len_nl_check(lst->buffer, buflen, len);
	*len += buflen;
	while (buflen == BUFFER_SIZE)
	{
		lst->next = ft_lstnew_gnl(fd, lst->next);
		lst = lst->next;
		if (!lst)
			return (head);
		buflen = ft_strlen_nl(lst->buffer);
		len_nl_check(lst->buffer, buflen, len);
		*len += buflen;
	}
	return (head);
}

char	*list_to_line(t_buffer **lst, size_t len)
{
	char	*next_line;
	size_t	i;
	size_t	j;

	i = 0;
	next_line = malloc(sizeof(char) * len + 1);
	if (!next_line)
		return (ft_bufclear(lst), NULL);
	next_line[len] = 0;
	while (lst && i < len)
	{
		j = 0;
		while ((*lst)->buffer[j] && i < len)
		{
			if ((*lst)->buffer[j] == '\n')
			{
				next_line[i++] = (*lst)->buffer[j];
				return (ft_clean_node(lst, next_line, j), next_line);
			}
			next_line[i++] = (*lst)->buffer[j++];
		}
		lst = ft_free_to_move(lst);
	}
	return (next_line);
}

char	*get_next_line(int fd)
{
	char			*next_line;
	size_t			len;
	static t_buffer	*lst;

	len = 0;
	next_line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_bufclear(&lst), NULL);
	if (lst)
	{
		len += ft_strlen_nl(lst->buffer);
		len_nl_check(lst->buffer, len, &len);
		if (lst->buffer[ft_strlen_nl(lst->buffer)] == '\n')
		{
			next_line = list_to_line(&lst, len);
			return (next_line);
		}
		lst->next = read_to_list(fd, lst->next, &len);
	}
	else
		lst = read_to_list(fd, lst, &len);
	if (!lst)
		return (NULL);
	next_line = list_to_line(&lst, len);
	return (next_line);
}
