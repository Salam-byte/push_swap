/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbibers <sbibers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:14:49 by sbibers           #+#    #+#             */
/*   Updated: 2024/10/19 11:14:38 by sbibers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

int					stack_len(t_node *head);
void				stack_init(t_node **a, char **str);
int					error_repeat(t_node *a, int number);
int					error_syntax(char *str);
t_node				*find_last_node(t_node *head);
t_node				*find_high(t_node *head);
void				free_stack(t_node **stack);
void				free_matrix(char **str);
char				**ft_split(char *str, char sep);
void				small_sorting(t_node **a, t_node **b);
void				sort_three(t_node **a);
void				pa(t_node **b, t_node **a);
void				pb(t_node **a, t_node **b);
void				rb(t_node **b);
void				ra(t_node **a);
void				rra(t_node **a);
void				rrb(t_node **b);
void				sa(t_node **a);
void				sb(t_node **b);
void				sort_1(int *array, t_node **a, t_node **b);
void				sort_2(int *array, t_node **a, t_node **b);
void				get_array(t_node **a, t_node **b);
void				messi_sorting(t_node **a, t_node **b);
void				sorting2(t_node **a, t_node **b, int manu, int len);
int					find_number(t_node *stack, int num);
int					find_index_of_manu(t_node *stack, int manu);
t_node				*find_high_and_index(t_node *stack, int *index);
int					sort_array(int *array, int len);
int					sort_array2(int *array, int len);
void				sort_1(int *array, t_node **a, t_node **b);
void				sort_2(int *array, t_node **a, t_node **b);

#endif
