/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:43:43 by sdarius-          #+#    #+#             */
/*   Updated: 2025/09/20 16:31:13 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	pop_stack(t_stack *stack)
{
	t_node	*tmp;
	int		value;

	if (!stack->head)
		exit(1);
	tmp = stack->head;
	value = stack->head->value;
	stack->head = tmp->next;
	free(tmp);
	stack->size--;
	return (value);
}

void	push_stack(t_stack *stack, int index, int value)
{
	t_node	*tmp;

	tmp = malloc(sizeof(t_node));
	if (!tmp)
		return ;
	tmp->value = value;
	tmp->index = index;
	tmp->next = stack->head;
	stack->head = tmp;
	stack->size++;
}

void	insersion_sort(int *nb, int count)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < count)
	{
		key = nb[i];
		j = i - 1;
		while (j >= 0 && nb[j] > key)
		{
			nb[j + 1] = nb[j];
			j--;
		}
		nb[j + 1] = key;
		i++;
	}
}

int	check_dublicates_bf(int *numbers, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (numbers[i] == numbers[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
