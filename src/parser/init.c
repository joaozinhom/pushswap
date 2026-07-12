/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 10:18:23 by mpinto-l          #+#    #+#             */
/*   Updated: 2026/07/10 15:01:12 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_valid_argument(t_node *stack, char *arg, long val)
{
	t_node	*tmp;

	if (!is_valid_number(arg) || !check_int_limit(arg))
		return (0);
	tmp = stack;
	while (tmp)
	{
		if (tmp->value == (int)val)
			return (0);
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
		val = ft_atoi(argv[i]);
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
	get_bench()->enabled = 0;
	*flag = 'a';
	if (!argv[i])
		return (0);
	if (ft_strncmp(argv[i], "--bench", 8) == 0)
	{
		get_bench()->enabled = 1;
		i++;
	}
	if (argv[i] && check_algorithm_flag(argv[i]))
	{
		*flag = get_algorithm(argv[i]);
		i++;
	}
	return (i);
}
