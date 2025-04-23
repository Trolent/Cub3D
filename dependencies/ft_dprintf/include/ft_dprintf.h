/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaetano <acaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:40:17 by acaetano          #+#    #+#             */
/*   Updated: 2024/06/11 12:07:50 by acaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H

# include <stdarg.h>
# include <unistd.h>

/* ************************************************************************** */
/*							 		FT_DPRINTF							  	  */
/* ************************************************************************** */

int				ft_dprintf(int fd, const char *format, ...);

int				ft_putstr_dpf(int fd, va_list args, int *len);
int				ft_putptr_dpf(int fd, va_list args, int *len);
int				ft_putnbr_dpf(int fd, va_list args, int *len);
int				ft_putunbr_dpf(int fd, va_list args, int *len);
int				ft_putchar_dpf(int fd, va_list args, int *len);
int				ft_putnbr_lbase_dpf(int fd, va_list args, int *len);
int				ft_putnbr_ubase_dpf(int fd, va_list args, int *len);

#endif
