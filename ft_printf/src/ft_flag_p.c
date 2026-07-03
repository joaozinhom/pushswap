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

int	ft_putadress(unsigned long nb)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
		count += ft_putadress(nb / 16);
	count += ft_putchar(base[nb % 16]);
	return (count);
}

int	ft_putpointer(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	count += ft_putadress((unsigned long)ptr);
	return (count);
}
