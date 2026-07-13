/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 10:33:44 by mpinto-l          #+#    #+#             */
/*   Updated: 2026/07/10 14:05:27 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	init_chunks(t_chunk *chunk, int stack_size)
{
	chunk->count = int_sqrt_ceil(stack_size);
	chunk->base = stack_size / chunk->count;
	chunk->rest = stack_size % chunk->count;
	chunk->start = 0;
}

static int	value_in_range(int value, int start, int end)
{
	if (value >= start && value < end)
		return (1);
	return (0);
}

static void	rotate_a_to_pos(t_node **stack_a, int pos, int size)
{
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(stack_a);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rra(stack_a);
	}
}

static int	find_chunk_pos(t_node *stack, int start, int end)
{
	int	pos;

	pos = 0;
	while (stack != NULL)
	{
		if (value_in_range(stack->value, start, end))
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

void	push_chunk(t_node **stack_a, t_node **stack_b, t_chunk *chunk)
{
	int	i;
	int	end;
	int	pos;
	int	size;

	i = 0;
	end = chunk->start + chunk->size;
	while (i < chunk->size)
	{
		size = stack_size(*stack_a);
		pos = find_chunk_pos(*stack_a, chunk->start, end);
		if (pos == -1)
			break ;
		rotate_a_to_pos(stack_a, pos, size);
		pb(stack_b, stack_a);
		i++;
	}
}
