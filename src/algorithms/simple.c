/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 09:29:56 by mpinto-l          #+#    #+#             */
/*   Updated: 2026/07/10 16:11:24 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

size_t	bubble_sorting(t_node **stack)
{
	size_t	i;
	int		max;

	i = 0;
	max = stack_max(*stack);
	while (disorder_metric(*stack) != 0.0)
	{
		if ((*stack)->value != max && (*stack)->value > (*stack)->next->value)
		{
			sa(stack);
			i++;
		}
		else
		{
			ra(stack);
			i++;
		}
	}
	return (i);
}

int	stack_min(t_node *stack)
{
	int	min;

	if (!stack)
		return (0);
	min = stack->value;
	while (stack != NULL)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

static void	to_top_min(t_node **stack, int pos, int size)
{
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

void	sort_three(t_node **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;
	if (a < b && b < c)
		return ;
	if (a > b && b < c && a < c)
		sa(stack);
	else if (a > b && b < c && a > c)
		ra(stack);
	else if (a < b && b > c && a < c)
	{
		rra(stack);
		sa(stack);
	}
	else if (a < b && b > c && a > c)
		rra(stack);
	else
	{
		sa(stack);
		rra(stack);
	}
}

void	small_sort(t_node **stack_a, t_node **stack_b)
{
	int	size;
	int	pos;

	size = stack_size(*stack_a);
	if (size <= 1)
		return ;
	if (size == 2)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
		return ;
	}
	while (stack_size(*stack_a) > 3)
	{
		pos = index_of(*stack_a, stack_min(*stack_a));
		to_top_min(stack_a, pos, stack_size(*stack_a));
		pb(stack_b, stack_a);
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}