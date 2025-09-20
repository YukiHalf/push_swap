/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 19:11:24 by sdarius-          #+#    #+#             */
/*   Updated: 2025/09/20 16:35:59 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(t_stack *stack, char x, bool print)
{
	t_node	*tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->head;
	stack->head = tmp->next;
	tmp->next = stack->head->next;
	stack->head->next = tmp;
	if (print)
	{
		write(1, "s", 1);
		write(1, &x, 1);
		write(1, "\n", 1);
	}
}

void	push(t_stack *stack_to, t_stack *stack_from, char x, bool print)
{
	int	index;

	if (!stack_from->head)
		return ;
	index = stack_from->head->index;
	push_stack(stack_to, index, pop_stack(stack_from));
	if (print)
	{
		write(1, "p", 1);
		write(1, &x, 1);
		write(1, "\n", 1);
	}
}

void	rotate(t_stack *stack, char x, bool print)
{
	t_node	*tmp;
	t_node	*end;

	if (stack->head == NULL || stack->head->next == NULL)
		return ;
	tmp = stack->head;
	stack->head = tmp->next;
	end = stack->head;
	while (end->next)
		end = end->next;
	tmp->next = NULL;
	end->next = tmp;
	if (print)
	{
		write(1, "r", 1);
		write(1, &x, 1);
		write(1, "\n", 1);
	}
}

void	r_rotate(t_stack *stack, char x, bool print)
{
	t_node	*b_end;
	t_node	*end;

	if (stack->head == NULL || stack->head->next == NULL)
		return ;
	end = stack->head;
	b_end = stack->head;
	while (b_end->next->next)
		b_end = b_end->next;
	while (end->next)
		end = end->next;
	end->next = stack->head;
	stack->head = end;
	b_end->next = NULL;
	if (print)
	{
		write(1, "rr", 2);
		write(1, &x, 1);
		write(1, "\n", 1);
	}
}
