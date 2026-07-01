

#include "pushswap.h"

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