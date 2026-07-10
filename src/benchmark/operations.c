/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinto-l <mpinto-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 09:33:20 by mpinto-l          #+#    #+#             */
/*   Updated: 2026/07/10 10:06:18 by mpinto-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	update_total(void)
{
	t_operations	*ops;

	ops = get_operations();
	ops->total = ops->sa + ops->sb + ops->ss;
	ops->total += ops->pa + ops->pb + ops->ra;
	ops->total += ops->rb + ops->rr + ops->rra;
	ops->total += ops->rrb + ops->rrr;
}

static void	update_op_count(char *name)
{
	if (!ft_strncmp(name, "sa", 3))
		get_operations()->sa++;
	else if (!ft_strncmp(name, "sb", 3))
		get_operations()->sb++;
	else if (!ft_strncmp(name, "ss", 3))
		get_operations()->ss++;
	else if (!ft_strncmp(name, "pa", 3))
		get_operations()->pa++;
	else if (!ft_strncmp(name, "pb", 3))
		get_operations()->pb++;
	else if (!ft_strncmp(name, "rra", 4))
		get_operations()->rra++;
	else if (!ft_strncmp(name, "rrb", 4))
		get_operations()->rrb++;
	else if (!ft_strncmp(name, "rrr", 4))
		get_operations()->rrr++;
	else if (!ft_strncmp(name, "ra", 3))
		get_operations()->ra++;
	else if (!ft_strncmp(name, "rb", 3))
		get_operations()->rb++;
	else if (!ft_strncmp(name, "rr", 3))
		get_operations()->rr++;
}

void	print_op(char *name)
{
	ft_printf("%s\n", name);
	update_op_count(name);
	update_total();
}
