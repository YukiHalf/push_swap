/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarius- <sdarius-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:44:01 by sdarius-          #+#    #+#             */
/*   Updated: 2025/08/13 18:43:00 by sdarius-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_digits(int argc, char **argv)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' '
				&& argv[i][j] != '-')
				return (-1);
			if (ft_isdigit(argv[i][j]) && (argv[i][j] == ' '
					|| argv[i][j] == '\0'))
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
    int     k;
	char	**str_numbers;
	int		*numbers;

	numbers = (int *)malloc(sizeof(int *) * count);
	if (!numbers)
		return (NULL);
    i = 0;
    j = 0;
    while(++i < argc)
    {
        *str_numbers[i] = ft_split(argv[i],' ');
        if(!str_numbers)
        display_error("",1);
        check_range(str_numbers,numbers);
        k = 0;
        while(str_numbers[k])
        numbers[j++] = str_numbers[k++];
    }
}
