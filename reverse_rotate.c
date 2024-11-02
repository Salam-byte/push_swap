/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 09:10:46 by sbibers           #+#    #+#             */
/*   Updated: 2024/10/19 11:15:22 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_node **stack)
{
	t_node	*head;
	t_node	*second;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	head = *stack;
	while (head->next->next)
		head = head->next;
	second = head->next;
	head->next = NULL;
	second->next = *stack;
	*stack = second;
}

void	rra(t_node **a)
// The last element becomes the first one.
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_node **b)
// The last element becomes the first one.
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}
