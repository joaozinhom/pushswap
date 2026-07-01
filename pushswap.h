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
void    swap_first_two(t_node **stack);
void    shiftdown(t_node **stack);
void    shiftup(t_node **stack);

// operators
void    sa(t_node **stack);
void    sb(t_node **stack);
void    ss(t_node **stack_a, t_node **stack_b);
void    pa(t_node **stack_a, t_node **stack_b);
void    pb(t_node **stack_b, t_node **stack_a);
void    ra(t_node **stack_a);
void    rb(t_node **stack_b);
void    rr(t_node **stack_a, t_node **stack_b);
void    rra(t_node **stack_a);
void    rrb(t_node **stack_b);
void    rrr(t_node **stack_a, t_node **stack_b);
#endif