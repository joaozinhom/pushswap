#include "pushswap.h"

void	pa(t_node **stack_a, t_node **stack_b)
{
	if (!stack_b || !*stack_b)
		return ;
	push_top(stack_a, pop_top(stack_b));
	print_op("pa");
}
