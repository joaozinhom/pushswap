/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 09:29:13 by mpinto-l          #+#    #+#             */
/*   Updated: 2026/07/10 14:05:28 by joamoren         ###   ########.fr       */
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
	{
		while (pos-- > 0)
			ra(stack);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rra(stack);
	}
}

int	find_pivot(t_node *stack, int size)
{
	int	min;
	int	max;
	int	i;

	min = stack->value;
	max = stack->value;
	i = 0;
	while (i++ < size)
	{
		if (stack->value < min)
			min = stack->value;
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return ((min + max) / 2);
}

int	partition(t_node **stack_a, t_node **stack_b, int size)
{
	int	pivot;
	int	pushed;
	int	rotated;
	int	i;

	pivot = find_pivot(*stack_a, size);
	pushed = 0;
	rotated = 0;
	i = 0;
	while (i++ < size)
	{
		if ((*stack_a)->value < pivot)
		{
			pb(stack_b, stack_a);
			pushed++;
		}
		else
		{
			ra(stack_a);
			rotated++;
		}
	}
	while (rotated-- > 0)
		rra(stack_a);
	return (pushed);
}

void	quick_sort(t_node **stack_a, t_node **stack_b, int size)
{
	int	pushed;
	int	i;

	if (size <= 1)
		return ;
	pushed = partition(stack_a, stack_b, size);
	if (pushed == 0 || pushed == size)
		return ;
	quick_sort(stack_a, stack_b, size - pushed);
	i = pushed;
	while (i-- > 0)
		pa(stack_a, stack_b);
	quick_sort(stack_a, stack_b, pushed);
}