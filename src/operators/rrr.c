/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinto-l <mpinto-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 10:07:09 by mpinto-l          #+#    #+#             */
/*   Updated: 2026/07/10 10:07:10 by mpinto-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rrr(t_node **stack_a, t_node **stack_b)
{
	shiftdown(stack_a);
	shiftdown(stack_b);
	print_op("rrr");
}
