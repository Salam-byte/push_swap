/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:16:22 by sbibers           #+#    #+#             */
/*   Updated: 2024/10/17 18:52:02 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void	swap(t_node **head)
{
	t_node	*first;
	t_node	*second;

	if (head == NULL || *head == NULL || stack_len(*head) == 1)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	if (first->next != NULL)
		first->next->prev = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	*head = second;
}

void	sa(t_node **a)
// Swap the first 2 elements at the top of stack a.
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_node **b)
// Swap the first 2 elements at the top of stack b.
{
	swap(b);
	write(1, "sb\n", 3);
}
