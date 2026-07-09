// header 

#include "pushswap.h"

static void	print_disorder(t_bench *bench)
{
	int		integer;
	int		decimal;
	double	disorder;

	disorder = bench->disorder * 100;
	integer = (int)disorder;
	decimal = (int)((disorder - integer) * 100);
	if (integer == 0 && decimal == 0)
        ft_printf("[bench] disorder: 0.00%%\n");
	else if(decimal < 10)
		ft_printf("[bench] disorder: %i.0%i%%\n", integer, decimal);
	else 
		ft_printf("[bench] disorder: %i.%i%%\n", integer, decimal);
}

static char	*get_complexity_name(int complexity)
{
	if (complexity == 0)
		return ("O(n²)");
	if (complexity == 1)
		return ("O(n√n)");
	return ("O(n log n)");
}

static void	print_strategy(t_bench *bench)
{
	ft_printf("[bench] strategy: %s / %s\n", bench->strategy, get_complexity_name(bench->complexity));
}


static void	print_total_ops(void) 
{
	t_operations	*ops;

	ops = get_operations();
	ft_printf("[bench] total_ops: %i\n", ops->total);
	ft_printf("[bench] sa: %i sb: %i ss: %i pa: %i pb: %i\n", 
	ops->sa, ops->sb, ops->ss, ops->pa ,ops->pb);
	ft_printf("[bench] ra: %i rb: %i rr: %i rra: %i rrb: %i rrr: %i\n",
	ops->ra, ops->rb, ops->rr, ops->rra, ops->rrb, ops->rrr);
}

void	print_bench(void)
{
	t_bench	*bench;

	bench = get_bench();
	if(!bench->enabled)
		return ;
	print_disorder(bench);
	print_strategy(bench);
	print_total_ops();
}
