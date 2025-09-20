/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 18:48:11 by sdarius-          #+#    #+#             */
/*   Updated: 2025/09/20 16:19:53 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	count_rot(t_node *stack, int index)
{
	int	c_rot;

	c_rot = 0;
	while (stack && stack->index != index)
	{
		stack = stack->next;
		c_rot++;
	}
	return (c_rot);
}

int	is_sorted(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->head;
	while (tmp->next)
	{
		if (tmp->next > tmp->next->next)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	free_stack(t_stack *stack)
{
	while (stack)
		pop_stack(stack);
}

int	get_min_index(t_stack *stack)
{
	t_node	*tmp;
	int		min_index;

	tmp = stack->head;
	min_index = tmp->index;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->index < min_index)
			min_index = tmp->index;
	}
	return (min_index);
}

void	sort(t_stack *stack_a, t_stack *stack_b, int *nb, int len)
{
	if (is_sorted(stack_a))
	{
		free(nb);
		free_stack(stack_a);
		display_error("", 1);
	}
	else if (len == 2)
		swap(stack_a, 'a', true);
	else if (len == 3)
		simple_sort(stack_a, len);
	else if (len <= 7)
		s_inser_sort(stack_a, stack_b, len);
	else if (len > 7)
	{
		k_sort1(stack_a, stack_b, len);
		move_back(stack_a, stack_b, len);
	}
	else
		display_error("", 1);
}
