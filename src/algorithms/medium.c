
#include "pushswap.h"

static int	value_in_range(int value, int start, int end)
{
	if (value >= start && value < end)
		return (1);
	return (0);
}

int	find_insert_pos(t_node *stack_b, int value)
{
	t_node	*node;
	int		pos;

	node = stack_b;
	pos = 0;
	while (node != NULL && node->value < value)
	{
		node = node->next;
		pos++;
	}
	return (pos);
}

void	rotate_b_to(t_node **stack_b, int pos, int size_b)
{
	int	steps_forward;
	int	steps_backward;
	int	i;

	steps_forward = pos;
	steps_backward = size_b - pos;
	i = 0;
	if (steps_forward <= steps_backward)
	{
		while (i < steps_forward)
		{
			rb(stack_b);
			i++;
		}
	}
	else
	{
		while (i < steps_backward)
		{
			rrb(stack_b);
			i++;
		}
	}
}

void	insert_sorted_b(t_node **stack_a, t_node **stack_b)
{
	int	value;
	int	pos;
	int	size_b;

	value = peek(*stack_a);
	size_b = stack_size(*stack_b);
	pos = find_insert_pos(*stack_b, value);
	rotate_b_to(stack_b, pos, size_b);
	pb(stack_b, stack_a);
}

void	push_chunk(t_node **stack_a, t_node **stack_b, int start, int end)
{
	int	remaining;
	int	i;
	int	top;

	remaining = stack_size(*stack_a);
	i = 0;
	while (i < remaining)
	{
		top = peek(*stack_a);
		if (value_in_range(top, start, end))
			insert_sorted_b(stack_a, stack_b);
		else
			ra(stack_a);
		i++;
	}
}

int	chunk_sorting(t_node **stack_a, t_node **stack_b)
{
	int	n;
	int	chunk_count;
	int	base;
	int	rest;
	int	start;
	int	size;
	int	i;

	n = stack_size(*stack_a);
	chunk_count = int_sqrt_ceil(n);
	base = n / chunk_count;
	rest = n % chunk_count;
	start = 0;
	i = 0;
	while (i < chunk_count)
	{
		size = base;
		if (i < rest)
			size++;
		push_chunk(stack_a, stack_b, start, start + size);
		start = start + size;
		i++;
	}
	return (0);
}