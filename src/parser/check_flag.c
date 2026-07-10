/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinto-l <mpinto-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 10:17:42 by mpinto-l          #+#    #+#             */
/*   Updated: 2026/07/10 10:17:44 by mpinto-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_algorithm_flag(char *str)
{
	if (ft_strncmp(str, "--simple", 9) == 0)
		return (1);
	if (ft_strncmp(str, "--medium", 9) == 0)
		return (1);
	if (ft_strncmp(str, "--complex", 10) == 0)
		return (1);
	if (ft_strncmp(str, "--adaptive", 11) == 0)
		return (1);
	return (0);
}

char	get_algorithm(char *str)
{
	if (ft_strncmp(str, "--simple", 8) == 0)
		return ('s');
	if (ft_strncmp(str, "--medium", 8) == 0)
		return ('m');
	if (ft_strncmp(str, "--complex", 9) == 0)
		return ('c');
	return ('a');
}
