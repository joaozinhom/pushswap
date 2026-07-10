/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinto-l <mpinto-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 09:32:46 by mpinto-l          #+#    #+#             */
/*   Updated: 2026/07/10 09:42:11 by mpinto-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_bench	*get_bench(void)
{
	static t_bench	bench;

	bench = (t_bench){FALSE, 0, 0.0, "Adaptive"};
	return (&bench);
}

t_operations	*get_operations(void)
{
	static t_operations	ops;

	ops = (t_operations){0};
	return (&ops);
}
