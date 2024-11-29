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

static long	ft_atoi_long(char *str, t_node **a)
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
	if (result == 0 && neg == -1)
	{
		write(2, "Error\n", 7);
		free_stack(a);
		exit(1);
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
			write(2, "Error\n", 7);
			return (free_stack(a));
		}
		number = ft_atoi_long(str[i], a);
		if (number > 2147483647 || number < -2147483648)
		{
			write(2, "Error\n", 7);
			return (free_stack(a));
		}
		if (error_repeat(*a, (int)number))
		{
			write(2, "Error\n", 7);
			return (free_stack(a));
		}
		add_node(a, (int)number);
	}
}
