/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinto-l <mpinto-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 15:35:56 by mpinto-l          #+#    #+#             */
/*   Updated: 2026/07/03 16:37:04 by mpinto-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int check_flag(char *str)
{
	if(ft_strncmp (str, "--simple", 8) == 0)
	{ 
		/* simple call */ 
	}
	else if(ft_strncmp (str, "--medium", 8) == 0)
	{ 
		/* simple call */ 
	}
	else if(ft_strncmp (str, "--complex", 9) == 0)
	{ 
		/* simple call */ 
	}
	else if(ft_strncmp (str, "--adaptative", 12) == 0)
	{ 
		/* simple call */ 
	}
	else if(ft_strncmp (str, "--bench", 7) == 0)
	{ 
		/* simple call */ 
	}
	else 
		return(print_actual_error());
}