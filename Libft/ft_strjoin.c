/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinto-l <mpinto-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 11:56:13 by mpinto-l          #+#    #+#             */
/*   Updated: 2026/06/06 11:56:21 by mpinto-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s3 = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!s3)
		return (NULL);
	ft_strlcpy(s3, s1, (s1_len + 1));
	ft_strlcat(s3, s2, (s1_len + s2_len + 1));
	return (s3);
}
