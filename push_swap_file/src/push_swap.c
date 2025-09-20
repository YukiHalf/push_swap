/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:31:26 by sdarius-          #+#    #+#             */
/*   Updated: 2025/09/20 16:19:53 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		count;
	int		*numbers;

	if (argc == 1)
		display_error("", 1);
	count = check_digits(argc, argv);
	numbers = get_numbers(argc, argv, count);
	if (count <= 1 || check_dublicates_bf(numbers, count))
	{
		free(numbers);
		if (count == 1)
			display_error("", 1);
		display_error("Error", 1);
	}
	init_stack(&stack_a, &stack_b, numbers, count);
	sort(&stack_a, &stack_b, numbers, count);
	free(numbers);
	free_stack(&stack_a);
	return (0);
}

void	init_stack(t_stack *stack_a, t_stack *stack_b, int *nb, int count)
{
	int		i;
	t_node	*tmp;

	stack_a->head = NULL;
	stack_b->head = NULL;
	stack_a->size = 0;
	stack_b->size = 0;
	i = count - 1;
	while (i >= 0)
	{
		push_stack(stack_a, 0, nb[i]);
		i--;
	}
	insersion_sort(nb, count);
	tmp = stack_a->head;
	while (tmp)
	{
		tmp->index = index_of(tmp->value, nb);
		tmp = tmp->next;
	}
}
