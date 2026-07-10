/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinto-l <mpinto-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 09:32:46 by mpinto-l          #+#    #+#             */
/*   Updated: 2026/07/10 11:47:52 by mpinto-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_bench	*get_bench(void)
{
	static t_bench	bench;
	static int		is_init;

	if (!is_init)
	{
		bench.enabled = FALSE;
		bench.complexity = 0;
		bench.disorder = 0.0;
		bench.strategy = "Adaptive";
		is_init = 1;
	}
	return (&bench);
}


t_operations	*get_operations(void)
{
	static t_operations	ops;
	static int			is_init;

	if (!is_init)
	{
		ops = (t_operations){0};
		is_init = 1;
	}
	return (&ops);
}