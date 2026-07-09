#include "pushswap.h"

void	rrr(t_node **stack_a, t_node **stack_b)
{
	shiftdown(stack_a);
	shiftdown(stack_b);
	print_op("rrr");
}
