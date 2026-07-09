#include "pushswap.h"

void	run_sort(t_node **stack_a, t_node **stack_b, char flag)
{
	double	d;

	d = disorder_metric(*stack_a);
	get_bench()->disorder = d;
	if (is_sorted(*stack_a))
	{
		get_bench()->strategy = "Adaptive";
		get_bench()->complexity = 0;
		return ;
	}
	if (flag == 's')
	{
		get_bench()->strategy = "Simple";
		get_bench()->complexity = 0;
		bubble_sorting(stack_a);
	}
	else if (flag == 'm')
	{
		get_bench()->strategy = "Medium";
		get_bench()->complexity = 1;
		chunk_sorting(stack_a, stack_b);
	}
	else if (flag == 'c')
	{
		get_bench()->strategy = "Complex";
		get_bench()->complexity = 2;
		quick_sort(t_node **a, t_node **b, int size); // placeholder — o algoritmo O(n log n) ainda não existe
	}
	else
	{
		get_bench()->strategy = "Adaptive";
		if (d < 0.2)
		{
			get_bench()->complexity = 0;
			bubble_sorting(stack_a);
		}
		else if (d < 0.5)
		{
			get_bench()->complexity = 1;
			chunk_sorting(stack_a, stack_b);
		}
		else
		{
			get_bench()->complexity = 2;
			ft_printf("complex\n"); // idem
		}
	}
}

static void	set_strategy(char *name, int complexity)
{
	get_bench()->strategy = name;
	get_bench()->complexity = complexity;
}

static void	run_complex(t_node **stack_a, t_node **stack_b)
{
	set_strategy("Complex", 2);
	quick_sort(stack_a, stack_b, ft_lstsize(*stack_a));
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
		run_complex(stack_a, stack_b);
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
		quick_sort(stack_a, stack_b, ft_lstsize(*stack_a));
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