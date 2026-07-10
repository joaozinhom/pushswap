/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 10:33:44 by mpinto-l          #+#    #+#             */
/*   Updated: 2026/07/10 14:05:27 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	find_insert_pos(t_node *stack_b, int value)
{
	int		pos;
	t_node	*node;

	pos = 0;
	node = stack_b;
	while (node != NULL && node->value < value)
	{
		node = node->next;
		pos++;
	}
	return (pos);
}

void	rotate_b_to(t_node **stack_b, int pos, int size_b)
{
	int	i;
	int	steps_forward;
	int	steps_backward;

	if (pos == size_b)
		return ;
	i = 0;
	steps_forward = pos;
	steps_backward = size_b - pos;
	if (steps_forward <= steps_backward)
	{
		while (i < steps_forward)
		{
			rb(stack_b);
			i++;
		}
	}
	else
	{
		while (i < steps_backward)
		{
			rrb(stack_b);
			i++;
		}
	}
}

void	insert_sorted_b(t_node **stack_a, t_node **stack_b)
{
	int	value;
	int	pos;
	int	size_b;

	value = peek(*stack_a);
	size_b = stack_size(*stack_b);
	pos = find_insert_pos(*stack_b, value);
	rotate_b_to(stack_b, pos, size_b);
	pb(stack_b, stack_a);
}
