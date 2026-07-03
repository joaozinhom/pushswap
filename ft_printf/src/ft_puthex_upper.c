/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinto-l <mpinto-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 15:12:28 by mpinto-l          #+#    #+#             */
/*   Updated: 2026/06/22 15:13:03 by mpinto-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_upper(unsigned int n)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789ABCDEF";
	if (n >= 16)
	{
		count += ft_puthex_upper(n / 16);
		count += ft_puthex_upper(n % 16);
	}
	else
		count += ft_putchar(base[n % 16]);
	return (count);
}
