/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 10:22:03 by mpinto-l          #+#    #+#             */
/*   Updated: 2026/07/10 15:42:38 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	set_strategy(char *name, int complexity)
{
	get_bench()->strategy = name;
	get_bench()->complexity = complexity;
}

static int	run_flag_strategy(t_node **stack_a, t_node **stack_b, char flag)
{
	if (flag == 's')
	{
		set_strategy("Simple", 0);
		bubble_sorting(stack_a);
	}
	else if (flag == 'm')
	{
		set_strategy("Medium", 1);
		chunk_sorting(stack_a, stack_b);
	}
	else if (flag == 'c')
	{
		set_strategy("Complex", 2);
		quick_sort(stack_a, stack_b, stack_size(*stack_a));
	}
	else
		return (0);
	return (1);
}

static void	run_adaptive(t_node **stack_a, t_node **stack_b, double disorder)
{
	int	size;

	size = stack_size(*stack_a);
	if (size <= 5)
	{
		set_strategy("Adaptive", 0);
		small_sort(stack_a, stack_b);
	}
	else if (size <= 200)
	{
		if (disorder < 0.5)
		{
			set_strategy("Adaptive", 1);
			chunk_sorting(stack_a, stack_b);
		}
		else
		{
			set_strategy("Adaptive", 2);
			quick_sort(stack_a, stack_b, size);
		}
	}
	else
	{
		set_strategy("Adaptive", 2);
		quick_sort(stack_a, stack_b, size);
	}
}

void	run_sort(t_node **stack_a, t_node **stack_b, char flag)
{
	double	disorder;

	disorder = disorder_metric(*stack_a);
	get_bench()->disorder = disorder;
	if (is_sorted(*stack_a))
	{
		set_strategy("Adaptive", 0);
		return ;
	}
	if (run_flag_strategy(stack_a, stack_b, flag))
		return ;
	run_adaptive(stack_a, stack_b, disorder);
}