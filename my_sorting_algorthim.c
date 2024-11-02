/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_sorting_algorthim.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:26:02 by sbibers           #+#    #+#             */
/*   Updated: 2024/11/02 17:35:10 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_number(t_node *stack, int num)
{
	while (stack)
	{
		if (stack->data < num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	sorting2(t_node **a, t_node **b, int manu, int len)
// push number from b to a.
{
	while (stack_len(*a) && len != 0 && find_number(*a, manu))
	{
		if ((*a)->data <= manu)
		{
			pb(a, b);
		}
		else
		{
			ra(a);
		}
		len--;
	}
}

void	messi_sorting(t_node **a, t_node **b)
// push number from b to a.
{
	int		size;
	int		index;
	t_node	*high;

	while (stack_len(*b) > 0)
	{
		size = stack_len(*b) / 2;
		high = find_high_and_index(*b, &index);
		if (index <= size)
		{
			while (*b != high)
				rb(b);
			pa(b, a);
		}
		else
		{
			while (*b != high)
				rrb(b);
			pa(b, a);
		}
	}
}

void	get_array(t_node **a, t_node **b)
// sort stack a.
{
	int	*array;
	int	len;

	len = stack_len(*a);
	array = (int *)malloc(len * sizeof(int));
	if (!array)
		return ;
	if (stack_len(*a) < 200)
	{
		sort_1(array, a, b);
	}
	else
	{
		sort_2(array, a, b);
	}
	sort_three(a);
	messi_sorting(a, b);
	free(array);
}
