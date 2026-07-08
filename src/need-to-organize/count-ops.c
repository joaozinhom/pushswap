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

t_operations *get_operations(void)
{
    static t_operations ops = {0};
    return (&ops);
}

void print_op(char *op)
{
    ft_putendl_fd(op, 1);
}

static void update_op_count(char *name)
{
    if (!ft_strncmp(name, "sa", 3))
		get_operations()->sa++;
	else if (!ft_strncmp(name, "sb", 3))
		get_operations()->sb++;
	else if (!ft_strncmp(name, "ss", 3))
		get_operations()->ss++;
	else if (!ft_strncmp(name, "pa", 3))
		get_operations()->pa++;
	else if (!ft_strncmp(name, "pb", 3))
		get_operations()->pb++;
	else if (!ft_strncmp(name, "rra", 4))
		get_operations()->rra++;
	else if (!ft_strncmp(name, "rrb", 4))
		get_operations()->rrb++;
	else if (!ft_strncmp(name, "rrr", 4))
		get_operations()->rrr++;
	else if (!ft_strncmp(name, "ra", 3))
		get_operations()->ra++;
	else if (!ft_strncmp(name, "rb", 3))
		get_operations()->rb++;
	else if (!ft_strncmp(name, "rr", 3))
		get_operations()->rr++;
}

void	print_op_name(char *name)
{
	//if (!*get_bench_flag())
	ft_printf("%s\n", name);
    update_op_count(name);
}