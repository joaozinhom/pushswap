#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../Libft/libft.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_node
{
    int             value;
    struct s_node   *next;
}   t_node;

size_t bubble_sorting(t_node **stack);
int	chunk_sorting(t_node **stack_a, t_node **stack_b);
double  disorder_metric(t_node *stack);
int	int_sqrt_ceil(int n);

// medium.c
int		int_sqrt_ceil(int n);
int		find_insert_pos(t_node *stack_b, int value);
void	rotate_b_to(t_node **stack_b, int pos, int size_b);
void	insert_sorted_b(t_node **stack_a, t_node **stack_b);
void	push_chunk(t_node **stack_a, t_node **stack_b, int start, int end);
int		chunk_sorting(t_node **stack_a, t_node **stack_b);

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
int     stack_max(t_node *stack);
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