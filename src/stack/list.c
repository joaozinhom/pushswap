// header 

#include "pushswap.h"

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

void	push_top(t_node **stack, t_node *node)
{
	if (stack && node)
	{
		node->next = *stack;
		*stack = node;
	}
}

t_node	*get_last(t_node *stack)
{
	t_node	*node;

	node = stack;
	if (stack == NULL)
		return (NULL);
	while (node->next != NULL)
		node = node->next;
	return (node);
}

void	add_back(t_node **stack, t_node *node)
{
	t_node	*last;

	if (!stack || !node)
		return ;
	if (*stack == NULL)
		*stack = node;
	else
	{
		last = get_last(*stack);
		last->next = node;
	}
}

void	free_stack(t_node **stack)
{
	t_node	*tmp;

	while (*stack != NULL)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}