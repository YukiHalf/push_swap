/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 20:25:35 by sdarius-          #+#    #+#             */
/*   Updated: 2025/08/06 20:49:14 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	char **numbers;
	int i;
	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);

	if (argc == 2)
		numbers = ft_split(argv[1], ' ');
	else
		numbers = &argv[1];
    i = 0;
    while(numbers[i])
    {
        
    }
}
