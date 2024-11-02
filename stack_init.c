/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:19:59 by sbibers           #+#    #+#             */
/*   Updated: 2024/10/19 09:22:20 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atoi_long(char *str)
// Convert the string to long value .
{
	long	result;
	int		neg;
	int		i;

	result = 0;
	neg = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * neg);
}

static void	add_node(t_node **stack, int number)
// Add node to stack .
{
	t_node	*node;

	if (stack == NULL)
		return ;
	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return ;
	node->data = number;
	node->next = NULL;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		find_last_node(*stack)->next = node;
		node->prev = find_last_node(*stack);
	}
}

void	stack_init(t_node **a, char **str)
// Check and add element to stack .
{
	long	number;
	int		i;

	i = -1;
	while (str[++i])
	{
		if (error_syntax(str[i]))
		{
			write(1, "syntax error", 13);
			return (free_stack(a));
		}
		number = ft_atoi_long(str[i]);
		if (number > 2147483647 || number < -2147483648)
		{
			write(1, "more or less than int\n", 23);
			return (free_stack(a));
		}
		if (error_repeat(*a, (int)number))
		{
			write(1, "repeated value\n", 16);
			return (free_stack(a));
		}
		add_node(a, (int)number);
	}
}
