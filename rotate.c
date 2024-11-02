/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:15:23 by sbibers           #+#    #+#             */
/*   Updated: 2024/10/19 11:15:19 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = find_last_node(*stack);
	last->next = first;
}

void	rb(t_node **b)
// The first element becomes the last one.
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	ra(t_node **a)
// The first element becomes the last one.
{
	rotate(a);
	write(1, "ra\n", 3);
}
