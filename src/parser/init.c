#include "pushswap.h"

int	is_valid_argument(t_node *stack, char *arg, long val)
{
	t_node	*tmp;

	if (!is_valid_number(arg) || !check_int_limit(arg))
		return (0);
	tmp = stack; // percorre a stack procurando duplicadas
	while (tmp)
	{
		if (tmp->value == (int)val)
			return (0); // se achar retorna 0
		tmp = tmp->next;
	}
	return (1);
}

t_node	*build_stack(char **argv, int start)
{
	t_node	*stack;
	int		i;
	long	val;

	stack = NULL;
	i = start;
	while (argv[i])
	{
		val = ft_atoi(argv[i]); // converte a string para numero
		if (!is_valid_argument(stack, argv[i], val))
		{
			free_stack(&stack);
			print_error_exit();
		}
		add_back(&stack, new_node((int)val));
		i++;
	}
	return (stack);
}

int	parse_flags(char **argv, char *flag, int *bench)
{
	int	i;

	i = 1;
	*bench = 0;
	*flag = 'a';// se nao mandar nenhuma flag passa direto para o adaptive
	if (!argv[i])
		return (0);
	if (ft_strncmp(argv[i], "--bench", 7) == 0) // --bench sempre vem primeiro
	{
		*bench = 1;
		i++;
	}
	if (argv[i] && check_algorithm_flag(argv[i])) // checa se tem flag
	{
		*flag = get_algorithm(argv[i]);
		i++;
	}
	return (i); // índice do primeiro número
}

void	run_sort(t_node **stack_a, t_node **stack_b, char flag)
{
	double	d;

	if (is_sorted(*stack_a)) // se ja estiver em ordem nao faz nada
		return ;
	if (flag == 's')
		bubble_sorting(stack_a);
	else if (flag == 'm')
		chunk_sorting(stack_a, stack_b);
	else if (flag == 'c')
		ft_printf("complex\n"); // drama :(
	else // adaptive
	{
		d = disorder_metric(*stack_a); // 0.0 = ordenado, 1.0 = fudido
		if (d < 0.2)
			bubble_sorting(stack_a);
		else if (d < 0.5)
			chunk_sorting(stack_a, stack_b);
		else
			ft_printf("complex\n"); // drama
	}
}