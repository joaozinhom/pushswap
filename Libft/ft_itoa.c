/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinto-l <mpinto-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 11:44:11 by mpinto-l          #+#    #+#             */
/*   Updated: 2026/06/06 11:53:00 by mpinto-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	number_size(int n);

char	*ft_itoa(int n)
{
	char	*ptr;
	long	nb;
	int		nb_size;

	nb = n;
	nb_size = number_size(n);
	ptr = malloc(sizeof(char) * (nb_size + 1));
	if (!ptr)
		return (NULL);
	ptr[nb_size] = '\0';
	if (nb < 0)
	{
		ptr[0] = '-';
		nb *= -1;
	}
	if (nb == 0)
		ptr[0] = '0';
	nb_size--;
	while (nb > 0)
	{
		ptr[nb_size] = (nb % 10) + '0';
		nb_size--;
		nb = nb / 10;
	}
	return (ptr);
}

static int	number_size(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size = 1;
	while (n != 0)
	{
		size++;
		n = n / 10;
	}
	return (size);
}
