// header

#include "pushswap.h"

static void	set_strategy(char *name, int complexity)
{
	get_bench()->strategy = name;
	get_bench()->complexity = complexity;
}

static int	run_flag_strategy(t_node **stack_a, t_node **stack_b, char flag)
{
	if (flag == 's')
	{
		set_strategy("Simple", 0);
		bubble_sorting(stack_a);
	}
	else if (flag == 'm')
	{
		set_strategy("Medium", 1);
		chunk_sorting(stack_a, stack_b);
	}
	else if (flag == 'c')
	{
		set_strategy("Complex", 2);
		quick_sort(stack_a, stack_b, stack_size(*stack_a));
	}
	else
		return (0);
	return (1);
}

static void	run_adaptive(t_node **stack_a, t_node **stack_b, double disorder)
{
	set_strategy("Adaptive", 0);
	if (disorder < 0.2)
		bubble_sorting(stack_a);
	else if (disorder < 0.5)
	{
		set_strategy("Adaptive", 1);
		chunk_sorting(stack_a, stack_b);
	}
	else
	{
		set_strategy("Adaptive", 2);
		quick_sort(stack_a, stack_b, stack_size(*stack_a));
	}
}

void	run_sort(t_node **stack_a, t_node **stack_b, char flag)
{
	double	disorder;

	disorder = disorder_metric(*stack_a);
	get_bench()->disorder = disorder;
	if (is_sorted(*stack_a))
	{
		set_strategy("Adaptive", 0);
		return ;
	}
	if (run_flag_strategy(stack_a, stack_b, flag))
		return ;
	run_adaptive(stack_a, stack_b, disorder);
}