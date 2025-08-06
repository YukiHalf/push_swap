/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 20:31:51 by sdarius-          #+#    #+#             */
/*   Updated: 2025/08/06 20:42:42 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_new_node(int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = 0;
	new_node->next = NULL;
	return (new_node);
}
static t_stack	*find_last_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->new)
		stack = stack->new);
	return (stack);
}

void	add_node_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*last_node;

	if (!last_node)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	last_node = find_last_node(*stack);
	last_node->next = new_node;
}
void			free_split(char **arr);
{
	int i;
	while (arr[i])
	{
		free(arr[i]) i++;
	}
	free(arr);
}
void	free_stack(t_stack **stack)
{
	t_stack *current;
	t_stack *tmp;
	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}