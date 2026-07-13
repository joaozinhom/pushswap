/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinto-l <mpinto-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 12:03:07 by mpinto-l          #+#    #+#             */
/*   Updated: 2026/06/22 15:10:07 by mpinto-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddress(int fd, unsigned long nb)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
		count += ft_putaddress(fd, nb / 16);
	count += ft_putchar(fd, base[nb % 16]);
	return (count);
}

int	ft_putpointer(int fd, void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return (ft_putstr(fd, "(nil)"));
	count += ft_putstr(fd, "0x");
	count += ft_putaddress(fd, (unsigned long)ptr);
	return (count);
}
