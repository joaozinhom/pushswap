#include "pushswap.h"

void	ra(t_node **stack_a)
{
	shiftup(stack_a);
	print_op("ra");
}
