/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 20:11:04 by sdarius-          #+#    #+#             */
/*   Updated: 2025/08/06 20:45:54 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
#include "../libft/libft.h"

typedef struct s_stack
{
    int value;
    int index;
    struct s_stack *next;
}   t_stack;

t_stack *create_new_node(int value);
void add_node_back(t_stack **stack,t_stack *new_node);
void free_split(char **arr);
void free_stack(t_stack **stack);
#endif