/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 09:29:31 by mpinto-l          #+#    #+#             */
/*   Updated: 2026/07/10 16:11:23 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	bring_max_and_pa(t_node **stack_a, t_node **stack_b)
{
	int	size;
	int	pos;

	size = stack_size(*stack_b);
	pos = index_of(*stack_b, stack_max(*stack_b));
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rb(stack_b);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rrb(stack_b);
	}
	pa(stack_a, stack_b);
}

int	chunk_sorting(t_node **stack_a, t_node **stack_b)
{
	t_chunk	chunk;
	int		i;

	if (!stack_a || !*stack_a)
		return (0);
	init_chunks(&chunk, stack_size(*stack_a));
	i = 0;
	while (i < chunk.count)
	{
		chunk.size = chunk.base;
		if (i < chunk.rest)
			chunk.size++;
		push_chunk(stack_a, stack_b, &chunk);
		chunk.start += chunk.size;
		i++;
	}
	while (*stack_b)
		bring_max_and_pa(stack_a, stack_b);
	return (0);
}
