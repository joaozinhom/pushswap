/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamoren <joamoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 10:06:49 by mpinto-l          #+#    #+#             */
/*   Updated: 2026/07/10 14:05:29 by joamoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pb(t_node **stack_b, t_node **stack_a)
{
	if (!stack_a || !*stack_a)
		return ;
	push_top(stack_b, pop_top(stack_a));
	print_op("pb");
}
