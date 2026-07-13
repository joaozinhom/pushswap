/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinto-l <mpinto-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 10:22:49 by mpinto-l          #+#    #+#             */
/*   Updated: 2026/07/10 10:22:53 by mpinto-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	reindex(t_node *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		stack->index = i;
		stack = stack->next;
		i++;
	}
}

t_node	*node_at(t_node *stack, int index)
{
	while (stack != NULL && index > 0)
	{
		stack = stack->next;
		index--;
	}
	return (stack);
}

int	index_of(t_node *stack, int value)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		if (stack->value == value)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

int	signed_distance(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (pos - size);
}

/* Replace each value by its rank (0..n-1). Sorting is order-preserving, so the
   emitted operations are identical, but downstream code can now rely on values
   being a dense 0..n-1 permutation: chunk ranges match and pivots cannot
   overflow. Ranks are staged in index first so in-place rewrite is safe. */
void	normalize_stack(t_node *stack)
{
	t_node	*node;
	t_node	*other;
	int		rank;

	node = stack;
	while (node != NULL)
	{
		rank = 0;
		other = stack;
		while (other != NULL)
		{
			if (other->value < node->value)
				rank++;
			other = other->next;
		}
		node->index = rank;
		node = node->next;
	}
	node = stack;
	while (node != NULL)
	{
		node->value = node->index;
		node = node->next;
	}
}
