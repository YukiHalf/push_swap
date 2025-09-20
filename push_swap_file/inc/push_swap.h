/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 20:11:04 by sdarius-          #+#    #+#             */
/*   Updated: 2025/09/20 16:35:28 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../../lib/libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*head;
	int				size;
}					t_stack;

int					check_digits(int argc, char **argv);
int					*get_numbers(int argc, char **argv, int count);
int					check_dublicates_bf(int *numbers, int count);
int					is_sorted(t_stack *stack);
int					get_min_index(t_stack *stack);
int					count_rot(t_node *stack, int index);

void				check_range(char **s_numbers, int *numbers);
void				init_stack(t_stack *stack_a, t_stack *stack_b, int *nb,
						int count);
void				sort(t_stack *stack_a, t_stack *stack_b, int *numbers,
						int count);
void				simple_sort(t_stack *stack, int len);
void				s_inser_sort(t_stack *stack_a, t_stack *stack_b, int len);
void				k_sort1(t_stack *stack_a, t_stack *stack_b, int length);
void				move_back(t_stack *stack_a, t_stack *stack_b, int length);
void				free_stack(t_stack *stack);
void				insersion_sort(int *nb, int count);
void				swap(t_stack *stack, char x, bool print);
void				push(t_stack *stack_to, t_stack *stack_from, char x,
						bool print);
void				rotate(t_stack *stack, char x, bool print);
void				r_rotate(t_stack *stack, char x, bool print);

void				push_stack(t_stack *stack, int index, int value);
int					pop_stack(t_stack *stack);
#endif
