#include "pushswap.h"
void    pa(t_node **stack_b, t_node **stack_a)
{
    if (!stack_a || !*stack_a)
        return ;
	push_top(stack_b, pop_top(*stack_a));
}