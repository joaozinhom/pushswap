/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinto-l <mpinto-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 10:34:13 by mpinto-l          #+#    #+#             */
/*   Updated: 2026/07/10 10:34:15 by mpinto-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	flag;
	int		start;

	if (argc < 2)
		return (0);
	start = parse_flags(argv, &flag);
	if (!argv[start])
		return (0);
	stack_a = build_stack(argv, start);
	stack_b = NULL;
	run_sort(&stack_a, &stack_b, flag);
	print_bench();
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
