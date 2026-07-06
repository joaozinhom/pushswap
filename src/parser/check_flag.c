/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinto-l <mpinto-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 15:35:56 by mpinto-l          #+#    #+#             */
/*   Updated: 2026/07/03 16:37:04 by mpinto-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int check_algorithm_flag(char *str)
{
	if (ft_strncmp(str, "--simple", 8) == 0)
		return (1);
	if (ft_strncmp(str, "--medium", 8) == 0)
		return (1);
	if (ft_strncmp(str, "--complex", 9) == 0)
		return (1);
	if (ft_strncmp(str, "--adaptive", 10) == 0)
		return (1);
	return (0);
}

char get_algorithm(char *str)
{
	if (ft_strncmp(str, "--simple", 8) == 0)
		return ('s');
	if (ft_strncmp(str, "--medium", 8) == 0)
		return ('m');
	if (ft_strncmp(str, "--complex", 9) == 0)
		return ('c');
	return ('a');
}
