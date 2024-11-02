/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:58:45 by sbibers           #+#    #+#             */
/*   Updated: 2024/10/19 09:24:50 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

static void	add_begin(t_node **stack, int data)
// Added at the beginning.
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
	{
		write(1, "wrong allocate", 15);
		exit(1);
	}
	node->data = data;
	node->next = *stack;
	*stack = node;
}

static void	push(t_node **stack_src, t_node **stack_dest)
{
	t_node	*tmp;

	if (stack_len(*stack_src) == 0)
		return ;
	tmp = *stack_src;
	*stack_src = (*stack_src)->next;
	add_begin(stack_dest, tmp->data);
	free(tmp);
}

void	pa(t_node **b, t_node **a)
// Take the first element at the top of b and put it at the top of a.
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b)
// Take the first element at the top of b and put it at the top of a.
{
	push(a, b);
	write(1, "pb\n", 3);
}
