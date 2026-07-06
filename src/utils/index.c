#include "pushswap.h"

/* Walks the stack and stamps each node with its current position (0 = top).
** Call it once after a batch of operations, then read node->index freely. */
void	reindex(t_node *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		stack->index = i;
		stack = stack->next;
		i++;
	}
}

t_node	*node_at(t_node *stack, int index)
{
	while (stack != NULL && index > 0)
	{
		stack = stack->next;
		index--;
	}
	return (stack);
}

int	index_of(t_node *stack, int value)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		if (stack->value == value)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

/* Cheapest way to bring position pos to the top of a stack of `size`:
** returns > 0 -> that many forward rotations (ra/rb),
** returns < 0 -> that many reverse rotations (rra/rrb). */
int	signed_distance(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (pos - size);
}
