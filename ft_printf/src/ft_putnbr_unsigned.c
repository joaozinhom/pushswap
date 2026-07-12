/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinto-l <mpinto-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 15:13:16 by mpinto-l          #+#    #+#             */
/*   Updated: 2026/06/22 15:16:19 by mpinto-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(int fd, unsigned int n)
{
	unsigned int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_putnbr_unsigned(fd, n / 10);
		count += ft_putnbr_unsigned(fd, n % 10);
	}
	else
		count += ft_putchar(fd, n + '0');
	return (count);
}
