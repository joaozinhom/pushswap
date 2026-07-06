#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	flag;
	int		bench;
	int		start;

	if (argc < 2)
		return (0);
	start = parse_flags(argv, &flag, &bench);
	if (!argv[start])
		return (0);
	stack_a = build_stack(argv, start);
	stack_b = NULL;
	run_sort(&stack_a, &stack_b, flag);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}