#include "pushswap.h"

void    rra(t_node **stack_a)
{
	shiftdown(stack_a);
	print_op("rra");
}
