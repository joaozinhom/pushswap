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

static int	value_in_range(int value, int start, int end)
{
	if (value >= start && value < end)
		return (1);
	return (0);
}

void	init_chunks(t_chunk *chunk, int stack_size)
{
	chunk->count = int_sqrt_ceil(stack_size);
	chunk->base = stack_size / chunk->count;
	chunk->rest = stack_size % chunk->count;
	chunk->start = 0;
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