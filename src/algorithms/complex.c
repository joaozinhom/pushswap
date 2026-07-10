/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinto-l <mpinto-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 09:29:13 by mpinto-l          #+#    #+#             */
/*   Updated: 2026/07/10 09:29:42 by mpinto-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	get_to_index(t_node **stack, int index)
{
	int	pos;
	int	size;

	pos = index_of(*stack, index);
	size = stack_size(*stack);
	if (pos <= size / 2)
		while (pos-- > 0)
			ra(stack);
	else
		while (pos++ < size)
			rra(stack);
}

int	find_pivot(t_node *stack, int size)
{
	int	i;
	int	min;
	int	max;

	i = 0;
	min = stack->value;
	max = stack->value;
	while (i < size)
	{
		if (stack->value < min)
			min = stack->value;
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
		i++;
	}
	return ((min + max) / 2);
}

int	partition(t_node **stack_a, t_node **stack_b, int size)
{
	int	pivot_value;
	int	i;
	int	count_below;

	pivot_value = find_pivot(*stack_a, size);
	i = 0;
	count_below = 0;
	while (i < size)
	{
		if ((*stack_a)->value < pivot_value)
		{
			pb(stack_b, stack_a);
			count_below++;
		}
		else
			ra(stack_a);
		i++;
	}
	return (count_below);
}

void	quick_sort(t_node **stack_a, t_node **stack_b, int size)
{
	int	count_below;
	int	i;

	if (size <= 1)
		return ;
	count_below = partition(stack_a, stack_b, size);
	quick_sort(stack_a, stack_b, size - count_below);
	i = count_below;
	while (i-- > 0)
		pa(stack_a, stack_b);
	quick_sort(stack_a, stack_b, count_below);
}
