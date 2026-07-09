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

int	parse_flags(char **argv, char *flag)
{
	int	i;

	i = 1;
	get_bench()->state = FALSE;
	*flag = 'a';// se nao mandar nenhuma flag passa direto para o adaptive
	if (!argv[i])
		return (0);
	if (ft_strncmp(argv[i], "--bench", 8) == 0) // --bench sempre vem primeiro
	{
		get_bench()->state = TRUE;
		i++;
	}
	if (argv[i] && check_algorithm_flag(argv[i])) // checa se tem flag
	{
		*flag = get_algorithm(argv[i]);
		i++;
	}
	return (i); // índice do primeiro número
}
