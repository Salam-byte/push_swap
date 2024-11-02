/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:18:26 by sbibers           #+#    #+#             */
/*   Updated: 2024/10/19 12:21:20 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	asc_order(t_node *head)
// If it is not in ascending order.
{
	if (head == NULL)
		return (0);
	while (head->next != NULL)
	{
		if (head->data > head->next->data)
			return (1);
		head = head->next;
	}
	return (0);
}

int	stack_len(t_node *head)
// Find the stack lengh.
{
	int	count;

	count = 0;
	if (head == NULL)
		return (0);
	while (head)
	{
		head = head->next;
		count++;
	}
	return (count);
}

int	main(int argc, char *argv[])
{
	char	**str;
	t_node	*b;
	t_node	*a;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		exit(1);
	else if (argc == 2)
	{
		str = ft_split(argv[1], ' ');
		stack_init(&a, str);
		free_matrix(str);
	}
	else
		stack_init(&a, argv + 1);
	if (asc_order(a))
	{
		if (stack_len(a) <= 5)
			small_sorting(&a, &b);
		else
			get_array(&a, &b);
	}
	free_stack(&a);
	return (0);
}
