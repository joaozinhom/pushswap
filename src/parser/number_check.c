/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinto-l <mpinto-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 10:18:59 by mpinto-l          #+#    #+#             */
/*   Updated: 2026/07/10 10:21:18 by mpinto-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_valid_number(char *str)
{
	int	i;

	if (str == NULL || str[0] == '\0') // ponteiro nulo
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
	{
		print_error_exit();// o sinal sozinho é invalido
		return (0);
	}
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
}
