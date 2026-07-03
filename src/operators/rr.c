#include "pushswap.h"

void    rr(t_node **stack_a, t_node **stack_b)
{
	shiftup(stack_a);
	shiftup(stack_b);
}
