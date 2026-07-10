/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinto-l <mpinto-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 10:07:22 by mpinto-l          #+#    #+#             */
/*   Updated: 2026/07/10 10:07:23 by mpinto-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// void ss(t_node **stack_a, t_node **stack_b)
// {
// 	sa(stack_a);
// 	sb(stack_b);
// } tava contando 2 vezes

void	ss(t_node **stack_a, t_node **stack_b)
{
	swap_first_two(stack_a);
	swap_first_two(stack_b);
	print_op("ss");
}
