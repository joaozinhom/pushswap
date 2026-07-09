// header 

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
// daria para passar esse peek direto para value_in_range e remover essa variavel top
void	push_chunk(t_node **stack_a, t_node **stack_b, t_chunk *chunk)
{
	int	i;
	int	top;
	int	end;
	int	remaining;

	i = 0;
	end = chunk->start + chunk->size;
	remaining = stack_size(*stack_a);
	while (i < remaining)
	{
		top = peek(*stack_a);
		if (value_in_range(top, chunk->start, end))
			insert_sorted_b(stack_a, stack_b);
		else
			ra(stack_a);
		i++;
	}
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
	return (0);
}
