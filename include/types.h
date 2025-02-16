/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:09:38 by trolland          #+#    #+#             */
/*   Updated: 2025/02/16 16:13:01 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TYPES_H
# define TYPES_H

typedef enum texture
{
    NO,
    SO,
    WE,
    EA,
    F,
    C
}	t_texture;

typedef struct s_row
{
    char   *map;
    struct s_row *next;
    struct s_row *prev;
}	t_row;

typedef struct s_map
{
    t_row  *raw;
    char   *no;
    char   *so;
    char   *we;
    char   *ea;
    char   *f;
    char   *c;
    int    width;
    int    height;
}	t_map;

#endif