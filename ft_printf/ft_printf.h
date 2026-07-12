/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinto-l <mpinto-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 11:41:19 by mpinto-l          #+#    #+#             */
/*   Updated: 2026/06/22 15:04:08 by mpinto-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(int fd, const char *str, ...);
int	check_format(int fd, va_list args, char c);

int	ft_putchar(int fd, char c);
int	ft_putstr(int fd, char *str);
int	ft_putnbr(int fd, int n);
int	ft_putnbr_unsigned(int fd, unsigned int n);
int	ft_puthex_lower(int fd, unsigned int n);
int	ft_puthex_upper(int fd, unsigned int n);
int	ft_putaddress(int fd, unsigned long nb);
int	ft_putpointer(int fd, void *ptr);

#endif
