
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

int is_sorted(t_node *stack)
{
    t_node  *node;

    node = stack;
    while (node != NULL && node->next != NULL)
    {
        if (node->value > node->next->value)
            return (0);
        node = node->next;
    }
    return (1);
}

int peek(t_node *stack)
{
    if (!stack)
        return (0);
    return (stack->value);
}
