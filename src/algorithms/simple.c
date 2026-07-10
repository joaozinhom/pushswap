/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 09:29:56 by mpinto-l          #+#    #+#             */
/*   Updated: 2026/07/10 14:05:30 by joamoren         ###   ########.fr       */
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
