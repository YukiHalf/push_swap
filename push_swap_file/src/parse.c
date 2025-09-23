/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:44:01 by sdarius-          #+#    #+#             */
/*   Updated: 2025/09/23 19:33:20 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	check_range(char **s_numbers, int *numbers)
{
	int	i;

	i = 0;
	while (s_numbers[i])
	{
		if (ft_atol(s_numbers[i]) < INT_MIN || ft_atol(s_numbers[i]) > INT_MAX
			|| ft_strlen(s_numbers[i]) > 11)
		{
			free2d(s_numbers);
			free(numbers);
			display_error("", 1);
		}
		i++;
	}
}

int	check_digits(int argc, char **argv)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' '
				&& argv[i][j] != '-')
				return (-1);
			if (ft_isdigit(argv[i][j]) && (argv[i][j + 1] == ' ' || argv[i][j
					+ 1] == '\0'))
				count += 1;
			j++;
		}
		i++;
	}
	return (count);
}

int	*get_numbers(int argc, char **argv, int count)
{
	int		i;
	int		j;
	int		k;
	char	**s_numbers;
	int		*numbers;

	numbers = (int *)malloc(sizeof(int) * count);
	if (!numbers)
		return (NULL);
	i = 0;
	j = 0;
	while (++i < argc)
	{
		s_numbers = ft_split(argv[i], ' ');
		if (!s_numbers)
		{
			free(numbers);
			display_error("", 1);
		}
		check_range(s_numbers, numbers);
		k = 0;
		while (s_numbers[k])
			numbers[j++] = ft_atoi(s_numbers[k++]);
		free2d(s_numbers);
	}
	return (numbers);
}
