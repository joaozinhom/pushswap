
#include "pushswap.h"

int stack_size(t_node *stack)
{
    int     i;
    t_node  *node;

    i = 0;
    node = stack;
    while (node != NULL)
    {
        node = node->next;
        i++;
    }
    return (i);
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


int peek(t_node *stack)
{
    if (!stack)
        return (0);
    return (stack->value);
}

void    swap_first_two(t_node **stack)
{
    t_node  *first;
    t_node  *second;

    if (!stack || !*stack || !(*stack)->next)
        return ;
    first = *stack;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack = second;
}