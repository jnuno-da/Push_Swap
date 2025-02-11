/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <jnuno-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:43:21 by jnuno-da          #+#    #+#             */
/*   Updated: 2025/02/10 19:43:21 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (info->size_a == 2)
    {
		if (info->stack_a->value > info->top_a->value)
			swap_a(info);
	}
	else if (info->size_a == 3)
	{
		case3(info);
		return;
	}
	else if (info->size_a > 3)
    {
		while (z++ < (info->size_a - 3))
			bigger_stacks(info);
		case3(info);
		while (info->stack_b)
			push_back(info);
		final_sort(info);
	}
	free_stacks(info);
}

int	check_double_sign(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (argv[i][j] == '-' || argv[i][j] == '+')
		j++;
	while (argv[i][j])
	{
		if (!ft_isdigit(argv[i][j]))
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
