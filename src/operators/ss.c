#include "pushswap.h"

// void ss(t_node **stack_a, t_node **stack_b)
// {
// 	sa(stack_a);
// 	sb(stack_b);
// } tava contando 2 vezes

void ss(t_node **stack_a, t_node **stack_b)
{
	swap_first_two(stack_a);
	swap_first_two(stack_b);
	print_op("ss");
}
