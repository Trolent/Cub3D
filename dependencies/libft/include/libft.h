/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:40:38 by acaetano          #+#    #+#             */
/*   Updated: 2025/04/16 22:04:52 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <errno.h>
# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 512
# define GNL_FLUSH -42

/* ************************************************************************** */
/*                                  LIBFT_H                                   */
/* ************************************************************************** */

ssize_t				ft_atos(char *str, bool *overflow);
void				ft_freetab(char **tab);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t				ft_tabsize(char **tab);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
bool				ft_isseparator(char c, char *sep);
char				**ft_split(char const *s, char *sep);
char				**ft_tabjoin(char **tab, char *str);

/* ************************************************************************** */
/*                                 LINKED_LST                                 */
/* ************************************************************************** */

typedef struct s_list
{
	struct s_list	*next;
	void			*content;
}					t_list;

void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
ssize_t				ft_lstsize(t_list *lst);
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
t_list				*ft_lstnew(void *content);

/* ************************************************************************** */
/*                                  FT_CTYPE                                  */
/* ************************************************************************** */

int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_isnumber(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);

/* ************************************************************************** */
/*                                 FT_STRING                                  */
/* ************************************************************************** */

void				ft_bzero(void *s, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
size_t				ft_strlen(const char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strndup(const char *s1, size_t size);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);

/* ************************************************************************** */
/*                                 FT_STDLIB                                  */
/* ************************************************************************** */

int					ft_atoi(const char *str);
void				*ft_calloc(size_t count, size_t size);
char				*ft_itoa(int n);
int					ft_max(int nb1, int nb2);

/* ************************************************************************** */
/*                               GET_NEXT_LINE                                */
/* ************************************************************************** */

typedef struct s_buffer
{
	struct s_buffer	*next;
	char			buffer[BUFFER_SIZE + 1];
}					t_buffer;

char				*get_next_line(int fd);
char				*list_to_line(t_buffer **lst, size_t len);
void				ft_bufclear(t_buffer **lst);
void				ft_clean_node(t_buffer **lst, char *next_line, size_t j);
t_buffer			**ft_free_to_move(t_buffer **lst);
t_buffer			*read_to_list(int fd, t_buffer *lst, size_t *len);
t_buffer			*ft_lstnew_gnl(int fd, t_buffer *lst);
size_t				ft_strlen_nl(char *s);
size_t				*len_nl_check(char *s, size_t buflen, size_t *len);
double				ft_modf(double x, double *iptr);

#endif
