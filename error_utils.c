/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <jnuno-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 11:49:06 by jnuno-da          #+#    #+#             */
/*   Updated: 2025/02/01 11:49:06 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_number(char *argv)
{
	long	num;
	int		i;
	int		sig;

	i = 0;
	sig = 1;
	if (argv[i] == '-' || argv[i] == '+')
	{
		if (argv[i] == '-')
			sig = -1;
		i++;
	}
	num = ft_atol(&argv[i]) * sig;
	if (num < INT_MIN || num > INT_MAX)
		return (-1);
	return (0);
}

int	check_error(char **argv)
{
	int	i;
	int j;
	char **split;

	i = 0;
	while (argv[++i])
	{
		if (ft_strchr(argv[i], ' '))
		{
			split = ft_split(argv[i], ' ');
			j = 0;
			while(split[j])
			{
				if (ft_strlen(split[j]) > 11 || check_number(split[j]) == -1 ||
					check_double_sign(&split[j]) == -1)
					return(free_split(split), -1);
				j++;
			}
			free_split(split);
		}
		else if (ft_strlen(argv[i]) > 11 || check_number(argv[i]) == -1 ||
					check_double_sign(&argv[i]) == -1)
				return (-1);
	}
	return (0);
}

int	check_for_duplicates(int *input, int list_size)
{
	int	i;
	int	j;

	i = 0;
	if (!input)
		return (-1);
	while (i < list_size)
	{
		j = i + 1;
		while (j < list_size)
		{
			if (input[i] == input[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_ordenated(int input_len, int *input)
{
	int	i;

	i = 0;
	while (i < (input_len - 1))
	{
		if (input[i] > input[i + 1])
			return (0);
		i++;
	}
	return (1);
}
