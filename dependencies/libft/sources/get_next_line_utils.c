/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaetano <acaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:27:19 by acaetano          #+#    #+#             */
/*   Updated: 2025/02/11 20:56:12 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	*len_nl_check(char *s, size_t buflen, size_t *len)
{
	if (s[buflen] == '\n')
		*len += 1;
	return (len);
}

t_buffer	*ft_lstnew_gnl(int fd, t_buffer *lst)
{
	ssize_t	bytes;

	lst = malloc(sizeof(t_buffer));
	if (!lst)
		return (NULL);
	lst->next = NULL;
	bytes = read(fd, lst->buffer, BUFFER_SIZE);
	if (bytes <= 0 || lst->buffer[0] == 0)
		return (ft_bufclear(&lst), NULL);
	while (bytes <= BUFFER_SIZE)
		lst->buffer[bytes++] = 0;
	return (lst);
}

void	ft_bufclear(t_buffer **lst)
{
	t_buffer	*next;

	next = NULL;
	while (*lst)
	{
		next = (*lst)->next;
		free(*lst);
		*lst = NULL;
		*lst = next;
	}
	*lst = NULL;
	next = NULL;
}

t_buffer	**ft_free_to_move(t_buffer **lst)
{
	t_buffer	*next;

	next = (*lst)->next;
	free(*lst);
	*lst = next;
	return (lst);
}

size_t	ft_strlen_nl(char *s)
{
	size_t	len;

	len = 0;
	while (s)
	{
		if (!s[0] || s[0] == '\n')
			return (len);
		if (!s[1] || s[1] == '\n')
			return (len + 1);
		if (!s[2] || s[2] == '\n')
			return (len + 2);
		if (!s[3] || s[3] == '\n')
			return (len + 3);
		if (!s[4] || s[4] == '\n')
			return (len + 4);
		if (!s[5] || s[5] == '\n')
			return (len + 5);
		if (!s[6] || s[6] == '\n')
			return (len + 6);
		if (!s[7] || s[7] == '\n')
			return (len + 7);
		s += 8;
		len += 8;
	}
	return (len);
}
