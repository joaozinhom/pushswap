/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinto-l <mpinto-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 15:17:17 by mpinto-l          #+#    #+#             */
/*   Updated: 2026/06/22 15:17:31 by mpinto-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(int fd, char *str)
{
	int	i;
	int	count;

	if (str == NULL)
		return (write(fd, "(null)", 6));
	i = 0;
	count = 0;
	while (str[i])
	{
		count += ft_putchar(fd, str[i]);
		i++;
	}
	return (count);
}
