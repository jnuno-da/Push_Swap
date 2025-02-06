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
	int j;
	int count;

	i = 0;
	count = 0;
	while (i < argc)
	{
		j = 0;
		while(argv[i][j])
		{
			if (argv[i][j] != ' ' && (j == 0 || argv[i][j - 1] == ' '))
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
int	*parse_input(char **argv, int argc)
{
	int *input; 
	char **split;
	int i;
	int	k;
	int j;

	i = 0;
	k = 0;
	input = malloc(sizeof(int) * count_args(argv, argc));
	if (!input)
		return (NULL);
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		j = 0;
		while (split[j] != NULL)
		{
			input[k++] = ft_atoi(split[j]);
			j++;
		}
		free_split(split);
		i++;
	}
	return (input);
}
int	*aux_input(int argc, char **argv)
{
	int *input;

	if (check_error(argv) < 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	input = parse_input(argv, argc);
	if (!input || check_for_duplicates(input, argc - 1) < 0)
	{
		ft_putstr_fd("Error\n", 2);
		free(input);
		return (NULL);	
	}
	if (is_ordenated(argc - 1, input))
		return (free(input), NULL);
	return (input);
}
void	free_split(char **split)
{
	int i;

	i = 0;
	if (!split)
		return ;
	while(split[i])
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
	if (argc)
	{
		if (argc == 2)
			input = parse_split(argv, argc);
		else
			input = aux_input(argc, argv);
		init_stacks(&info);
		create_stacks(input, argc - 1, &info);
		free(input);
		init_index(&info);
		push_swap(&info);
	}
	return (0);
}
