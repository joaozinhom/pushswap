/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinto-l <mpinto-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 15:28:35 by mpinto-l          #+#    #+#             */
/*   Updated: 2026/07/03 16:37:07 by mpinto-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int check_duplicate(int *stack, int size, int num)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (stack[i] == num)
			return (1);
		i++;
	}
	return (0);
}

int	is_valid_number(char *str)
{
	int	i;

	if (str == NULL || str[0] == '\0') // ponteiro nulo
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0') // o sinal sozinho é invalido
		return(print_actual_error(), 0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_int_limit(char *str)
{
	int	len;
	int	is_negative;

	len = 0;
	is_negative = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			is_negative = 1;
		str++;
	}
	if (str[0] == '\0')
		return (0);
	while (str[len])
		len++;
	if (len > 10)
		return (0);
	else if (len < 10)
		return (1);
	else if (is_negative) // caso tenha 10 digitos
		return (ft_strncmp(str, "2147483648", 10) <= 0); // se strcmp for > 0, o numero e menor que -2147483648
    else 
        return (ft_strncmp(str, "2147483647", 10) <= 0); // se strcmp for > 0, o numero e maior que 2147483647
	return(print_actual_error());
}