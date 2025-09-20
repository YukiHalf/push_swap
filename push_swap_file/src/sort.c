/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:33:40 by sdarius-          #+#    #+#             */
/*   Updated: 2025/09/20 16:35:46 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_rot_sort(t_stack *stack)
{
	int	head_value;
	int	next_value;
	int	n_next_value;

	head_value = stack->head->value;
	next_value = stack->head->next->value;
	n_next_value = stack->head->next->next->value;
	if (head_value < next_value && next_value < n_next_value)
		return (1);
	if (next_value < n_next_value && head_value > n_next_value)
		return (1);
	if (n_next_value < head_value && head_value < next_value)
		return (1);
	return (0);
}

void	simple_sort(t_stack *stack, int len)
{
	int	min_index;
	int	r;

	if (is_sorted(stack))
		return ;
	min_index = get_min_index(stack);
	r = count_rot(stack->head, min_index);
	if (is_rot_sort(stack))
	{
		if (r < len - r)
			rotate(stack, 'a', true);
		else
			r_rotate(stack, 'a', true);
	}
	else
	{
		swap(stack, 'a', true);
		if (is_sorted(stack))
			return ;
		if (r < len - r)
			rotate(stack, 'a', true);
		else
			r_rotate(stack, 'a', true);
	}
}

void	s_inser_sort(t_stack *stack_a, t_stack *stack_b, int len)
{
	int	min_index;
	int	iter;
	int	len_b;

	iter = 0;
	len_b = len;
	while (iter++ < len_b - 3)
	{
		min_index = get_min_index(stack_a);
		if (count_rot(stack_a->head, min_index) <= len_b - min_index
			- count_rot(stack_a->head, min_index))
			while (stack_a->head->index != min_index)
				rotate(stack_a, 'a', true);
		else
			while (stack_a->head->index != min_index)
				r_rotate(stack_a, 'a', true);
		if (is_sorted(stack_a) && stack_b->size == 0)
			return ;
		push(stack_b, stack_a, 'b', true);
		len--;
	}
	simple_sort(stack_a, len);
	iter = 0;
	while (iter++ < len_b - 3)
		push(stack_a, stack_b, 'a', true);
}

void	k_sort1(t_stack *stack_a, t_stack *stack_b, int length)
{
	int	i;
	int	range;

	i = 0;
	range = ft_sqrt(length) * 14 / 10;
	while (stack_a->head)
	{
		if (stack_a->head->index <= i)
		{
			push(stack_b, stack_a, 'b', true);
			rotate(stack_b, 'b', true);
			i++;
		}
		else if (stack_a->head->index <= i + range)
		{
			push(stack_b, stack_a, 'b', true);
			i++;
		}
		else
			rotate(stack_a, 'a', true);
	}
}

void	move_back(t_stack *stack_a, t_stack *stack_b, int length)
{
	int	rb_count;
	int	rrb_count;

	while (length - 1 >= 0)
	{
		rb_count = count_rot(stack_b->head, length - 1);
		rrb_count = (length + 3) - rb_count;
		if (rb_count <= rrb_count)
		{
			while (stack_b->head->index != length - 1)
				rotate(stack_b, 'b', true);
			push(stack_a, stack_b, 'a', true);
			length--;
		}
		else
		{
			while (stack_b->head->index != length - 1)
				r_rotate(stack_b, 'b', true);
			push(stack_a, stack_b, 'a', true);
			length--;
		}
	}
}
