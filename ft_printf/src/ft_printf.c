/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinto-l <mpinto-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 12:03:00 by mpinto-l          #+#    #+#             */
/*   Updated: 2026/06/22 15:10:31 by mpinto-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(va_list args, char flag)
{
	int		count;

	count = 0;
	if (flag == 'd' || flag == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (flag == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (flag == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (flag == 'x')
		count += ft_puthex_lower(va_arg(args, unsigned int));
	else if (flag == 'X')
		count += ft_puthex_upper(va_arg(args, unsigned int));
	else if (flag == 'u')
		count += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (flag == 'p')
		count += ft_putpointer(va_arg(args, void *));
	else if (flag == '%')
		return (ft_putchar('%'));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] != '\0')
				count += check_format(args, str[i + 1]);
			i++;
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
