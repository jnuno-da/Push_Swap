/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 11:39:45 by jnuno-da          #+#    #+#             */
/*   Updated: 2025/02/01 11:39:47 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_args(char **argv, int argc)
{
	int	i;
	int	count;

	count = 0;
	if(argc == 2)
	{
		i = 0;
		while (argv[1][i])
		{
			while (argv[1][i])
			{
				if (argv[1][i] != ' ' && (i == 0 || argv[1][i - 1] == ' '))
					count++;
				i++;
			}
		}
	}
	else
		count = argc - 1;
	return (count);
}

int	*parse_input(char **argv, int argc)
{
	int		*input;
	char	**split;
	int		i;

	input = malloc(sizeof(int) * count_args(argv, argc));
	if (!input)
		return (NULL);
	i = -1;
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		while (split[++i])
			input[i] = ft_atoi(split[i]);
		free_split(split);
	}
	else
	{
		while(++i < count_args(argv, argc))
			input[i] = ft_atoi(argv[i + 1]);
	}
	return (input);
}

int	*aux_input(int argc, char **argv)
{
	int	*input;

	if (check_error(argv) < 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	input = parse_input(argv, argc);
	if (!input || check_for_duplicates(input, count_args(argv, argc)) < 0)
	{
		ft_putstr_fd("Error\n", 2);
		free(input);
		return (NULL);
	}
	if (is_ordenated(count_args(argv, argc), input)) 
	{
		free(input);
		return (NULL);
	}
	return (input);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	main(int argc, char **argv)
{
	t_info	info;
	int		*input;

	input = NULL;
	if (argc <= 1)
		return (0);
	input = aux_input(argc, argv);
	if (!input)
		return (0);
	init_stacks(&info);
	create_stacks(input, count_args(argv, argc), &info);
	free(input);
	init_index(&info);
	push_swap(&info);
	return (0);
}
