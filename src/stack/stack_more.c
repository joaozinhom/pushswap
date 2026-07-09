// header 

#include "pushswap.h"

int	peek(t_node *stack)
{
	if (!stack)
		return (0);
	return (stack->value);
}

t_node  *pop_top(t_node **stack)
{
    t_node  *node;

    if (!stack || !*stack)
        return (NULL);
    node = *stack;
    *stack = (*stack)->next;
    node->next = NULL;
    return (node);
}

void shiftup(t_node **stack)
{
    t_node  *actual;
    int     carry;

    if (!stack || !*stack || !(*stack)->next)
        return ;
    carry = (*stack)->value;
    actual = *stack;
    while (actual->next != NULL)
    {
        actual->value = actual->next->value;
        actual = actual->next;
    }
    actual->value = carry;
}


void shiftdown(t_node **stack)
{
    t_node  *actual;
    int     carry;
    int     temp;

    if (!stack || !*stack || !(*stack)->next)
        return ;
    actual = *stack;
    while (actual->next != NULL)
        actual = actual->next;
    carry = actual->value;
    actual = *stack;
    while (actual != NULL)
    {
        temp = actual->value;
        actual->value = carry;
        carry = temp;
        actual = actual->next;
    }
}