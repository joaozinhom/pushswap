/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinto-l <mpinto-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 10:06:45 by mpinto-l          #+#    #+#             */
/*   Updated: 2026/07/10 10:06:46 by mpinto-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pa(t_node **stack_a, t_node **stack_b)
{
	if (!stack_b || !*stack_b)
		return ;
	push_top(stack_a, pop_top(stack_b));
	print_op("pa");
}
