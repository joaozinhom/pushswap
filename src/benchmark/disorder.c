/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinto-l <mpinto-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 09:33:12 by mpinto-l          #+#    #+#             */
/*   Updated: 2026/07/10 10:05:11 by mpinto-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

double	disorder_metric(t_node *stack)
{
	t_node	*i;
	t_node	*j;
	size_t	mistakes;
	size_t	total_pairs;

	mistakes = 0;
	total_pairs = 0;
	i = stack;
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			if (i->value > j->value)
				mistakes++;
			total_pairs++;
			j = j->next;
		}
		i = i->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / (double)total_pairs);
}
