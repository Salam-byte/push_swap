/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 09:08:40 by sbibers           #+#    #+#             */
/*   Updated: 2024/10/13 11:27:21 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_repeat(t_node *a, int number)
// If I have two similar numbers
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->data == number)
			return (1);
		a = a->next;
	}
	return (0);
}

int	error_syntax(char *str)
// Inputs are not numbers
{
	if (*str == '\0')
		return (1);
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
		str++;
	}
	return (0);
}
