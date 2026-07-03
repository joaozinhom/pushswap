/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinto-l <mpinto-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 11:45:20 by mpinto-l          #+#    #+#             */
/*   Updated: 2026/06/09 11:17:31 by mpinto-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*pdest;
	unsigned char	*psrc;

	if (dest == src)
		return (dest);
	pdest = (unsigned char *)dest;
	psrc = (unsigned char *)src;
	if (pdest > psrc)
		while (n--)
			*(pdest + n) = *(psrc + n);
	else
		while (n--)
			*pdest++ = *psrc++;
	return (dest);
}
