/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallest_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 19:00:05 by sbibers           #+#    #+#             */
/*   Updated: 2024/10/19 09:23:56 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*find_less(t_node *stack)
// Find the less elemenet.
{
	t_node	*min_node;

	if (stack == NULL)
		return (NULL);
	min_node = stack;
	stack = stack->next;
	while (stack)
	{
		if (stack->data < min_node->data)
		{
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

void	sort_three(t_node **a)
// Sort three element.
{
	t_node	*high;

	high = find_high(*a);
	if (*a == high)
		ra(a);
	else if ((*a)->next == high)
		rra(a);
	if ((*a)->data > (*a)->next->data)
		sa(a);
}

static void	sort_four(t_node **a, t_node **b)
// Sorting four element.
{
	t_node	*less;

	while (stack_len(*a) > 3)
	{
		less = find_less(*a);
		if (less == *a)
			pb(a, b);
		else if (less == (*a)->next)
		{
			sa(a);
			pb(a, b);
		}
		else if (less == (*a)->next->next)
		{
			ra(a);
			ra(a);
			pb(a, b);
		}
		else
			rra(a);
	}
	sort_three(a);
	while (stack_len(*b) > 0)
		pa(b, a);
}

static void	sort_five(t_node **a, t_node **b)
// Sorting five element.
{
	t_node	*less;

	while (stack_len(*a) > 3)
	{
		less = find_less(*a);
		if (less == *a)
			pb(a, b);
		else if (less == (*a)->next)
		{
			sa(a);
			pb(a, b);
		}
		else if (less == (*a)->next->next)
		{
			ra(a);
			ra(a);
			pb(a, b);
		}
		else
			rra(a);
	}
}

void	small_sorting(t_node **a, t_node **b)
// Sorting small stack.
{
	if (stack_len(*a) == 2)
		sa(a);
	else if (stack_len(*a) == 3)
		sort_three(a);
	else if (stack_len(*a) == 4)
		sort_four(a, b);
	else if (stack_len(*a) == 5)
	{
		sort_five(a, b);
		sort_three(a);
		while (stack_len(*b) > 0)
			pa(b, a);
	}
}
