// header 

#include "pushswap.h"

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

int	signed_distance(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (pos - size);
}
