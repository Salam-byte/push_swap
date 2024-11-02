/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_sorting_algorthim2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 08:48:04 by sbibers           #+#    #+#             */
/*   Updated: 2024/10/21 16:56:46 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_array(int *array, int len)
// sort array to find a medain.
{
	int	swap;
	int	pass;
	int	temp;
	int	i;

	swap = 1;
	pass = 0;
	while (swap)
	{
		swap = 0;
		i = 0;
		while (i < len - 1 - pass)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swap = 1;
			}
			i++;
		}
		pass++;
	}
	return (array[len / 4]);
}

int	sort_array2(int *array, int len)
// sort array to find a medain.
{
	int	swap;
	int	pass;
	int	temp;
	int	i;

	swap = 1;
	pass = 0;
	while (swap)
	{
		swap = 0;
		i = 0;
		while (i < len - 1 - pass)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swap = 1;
			}
			i++;
		}
		pass++;
	}
	return (array[len / 15]);
}

t_node	*find_high_and_index(t_node *stack, int *index)
// find the highest number in stack a.
{
	int		i;
	int		highest;
	t_node	*high;

	i = 0;
	*index = 0;
	high = stack;
	highest = stack->data;
	stack = stack->next;
	while (stack != NULL)
	{
		if (stack->data > highest)
		{
			highest = stack->data;
			high = stack;
			*index = i + 1;
		}
		i++;
		stack = stack->next;
	}
	return (high);
}

int	find_index_of_manu(t_node *stack, int manu)
// find the index of median in stack a.
{
	int	index;

	index = 0;
	while (stack)
	{
		if (stack->data == manu)
			return (index);
		stack = stack->next;
		index++;
	}
	return (-1);
}
