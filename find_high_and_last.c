/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_high_and_last.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:28:02 by sbibers           #+#    #+#             */
/*   Updated: 2024/10/19 09:23:14 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

t_node	*find_high(t_node *head)
// Find the max nimber of stack.
{
	int		highest;
	t_node	*high;

	if (head == NULL)
		return (NULL);
	highest = head->data;
	high = head;
	head = head->next;
	while (head)
	{
		if (head->data > highest)
		{
			highest = head->data;
			high = head;
		}
		head = head->next;
	}
	return (high);
}

t_node	*find_last_node(t_node *head)
// Find the last node of stack.
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}
