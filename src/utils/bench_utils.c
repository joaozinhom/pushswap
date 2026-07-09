#include "pushswap.h"

// typedef struct s_operations // conta a quantidade de operacoes
// {
// 	int	sa;
// 	int	sb;
// 	int	ss;
// 	int	pa;
// 	int	pb;
// 	int	ra;
// 	int	rb;
// 	int	rr;
// 	int	rra;
// 	int	rrb;
// 	int	rrr;

// } t_operations;

// typedef struct s_bench
// {
// 	int		total;
// 	int		complexity;
// 	double	disorder;
// 	char	*strategy;

// } t_bench;

t_bench	*get_bench(void)
{
	static t_bench	bench = {FALSE, 0, 0.0, "Adaptive"};
	return (&bench);
}

