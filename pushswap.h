#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
    int             value;
    struct s_node   *next;
}   t_node;

// list.c
t_node  *new_node(int value);
void    push_top(t_node **stack, t_node *node);
t_node  *get_last(t_node *stack);
void    add_back(t_node **stack, t_node *node);
void    free_stack(t_node **stack);

// stack.c
int     stack_size(t_node *stack);
t_node  *pop_top(t_node **stack);
int     is_sorted(t_node *stack);
int     peek(t_node *stack);

#endif