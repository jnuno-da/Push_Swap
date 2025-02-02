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
	long		num;
	int		i;
	int		sig;

	i = 0;
	sig = 0;
	if (argv[i] == '-' || argv[i] == '+')
	{
		if(argv[i] == '-')
			sig = -1;
		else
			sig++;
		i++;
	}
	num = ft_atol(&argv[i]);
	if (num > 2147483647)
		return (-1);
	if (num * sig < INT_MIN || num * sig > INT_MAX)
		return (-1);
	return (0);
}

int	check_error(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (ft_strlen(argv[i]) > 11)
			return (-1);
		if (check_number(argv[i]) == -1)
				return (-1);
		if (check_double_sign(&argv[i]) == -1)
				return(-1);
	}
	return (0);
}

static int	compare(int input, int *tmp, int z)
{
	int	i;

	i = 0;
	while (i < z)
	{
		if (input == tmp[i])
		{
			free(tmp);
			return (1);
		}
		i++;
	}
	return (0);
}

int	*check_for_duplicates(int *input, char **argv, int list_size)
{
	int	i;
	int	j;
	int	z;
	int	*temp;

	input = malloc((list_size) * sizeof(int));
	temp = malloc((list_size) * sizeof(int));
	i = 0;
	j = list_size -1;
	z = 0;
	while (argv[++i])
	{
		input[j] = ft_atoi(argv[i]);
		if (compare(input[j], temp, z))
		{
			free(input);
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		temp[z++] = input[j--];
	}
	free(temp);
	return (input);
}

int	is_ordenated(int input_len, int *input)
{
	int	i;

	i = 0;
	while (i < (input_len - 1))
	{
		if (input[i] < input[i + 1])
			return (0);
		i++;
	}
	free(input);
	return (1);
}
