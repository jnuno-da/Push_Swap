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

int		check_double_sign(char **argv)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while(argv[i][j])
	{
		if (argv[i][j] == '-')
		{
			if (j > 0)
				return(-1);
		}
		else if (!ft_isdigit(argv[i][j]))
			return (-1);
		j++;
	}
	return (0);
}
void	free_stacks(t_info *info)
{
	t_lst	*temp;

	while (info->stack_a)
	{
		temp = info->stack_a;
		info->stack_a = temp->next;
		free(temp);
	}
}

void	final_sort(t_info *info)
{
	t_lst	*temp;
	int		i;

	i = 0;
	temp = info->top_a;
	find_max(info);
	while (temp->value != info->max)
	{
		i++;
		temp = temp->prev;
	}
	if (i <= (info->size_a / 2))
	{
		while (info->stack_a->value != info->max)
			rotate_a(info, 0);
	}
	else
	{
		while (info->stack_a->value != info->max)
			reverse_rotate_a(info, 0);
	}
}

void	push_swap(t_info *info)
{
	int	z;

	z = 0;
	if (info->size_a > 2)
	{
		while (z++ < (info->size_a - 3))
			bigger_stacks(info);
		case3(info);
		while (info->stack_b)
			push_back(info);
	}
	final_sort(info);
	free_stacks(info);
}

int	main(int argc, char **argv)
{
	t_info	info;
	int		*input;

	input = NULL;
	if (argc <= 1)
		return (0);
	if (check_error(argv) < 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	input = check_for_duplicates(input, argv, argc -1);
	if (is_ordenated(argc - 1, input))
		return (0);
	init_stacks(&info);
	create_stacks(input, argc - 1, &info);
	free(input);
	init_index(&info);
	push_swap(&info);
	return (0);
}
