/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:31:26 by sdarius-          #+#    #+#             */
/*   Updated: 2025/08/13 18:00:29 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc ,char **argv)
{
    t_stack stack_a;
    t_stack stack_b;
	int count;
	int *numbers;
    if(argc == 1)
        display_error("",1);
	count = check_digits(argc,argv);
    numbers = get_numbers(argc,argv,count);
}
