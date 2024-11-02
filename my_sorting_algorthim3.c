/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_sorting_algorthim3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 10:59:49 by sbibers           #+#    #+#             */
/*   Updated: 2024/10/19 11:23:14 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_1(int *array, t_node **a, t_node **b)
{
	int		i;
	int		len;
	int		manu;
	t_node	*stack;

	while (stack_len(*a) > 3)
	{
		i = 0;
		stack = *a;
		while (stack)
		{
			array[i] = stack->data;
			i++;
			stack = stack->next;
		}
		len = stack_len(*a);
		manu = sort_array(array, len);
		sorting2(a, b, manu, len);
	}
}

void	sort_2(int *array, t_node **a, t_node **b)
{
	int		i;
	int		len;
	int		manu;
	t_node	*stack;

	len = stack_len(*a);
	while (stack_len(*a) > 3)
	{
		i = 0;
		stack = *a;
		while (stack)
		{
			array[i] = stack->data;
			i++;
			stack = stack->next;
		}
		manu = sort_array2(array, len);
		sorting2(a, b, manu, len);
	}
}
