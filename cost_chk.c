/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_chk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 11:39:10 by jnuno-da          #+#    #+#             */
/*   Updated: 2025/02/01 11:46:09 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int i)
{
	if (i < 0)
		return (i * (-1));
	return (i);
}

int	fin_max_index(t_info *info)
{
	t_lst	*temp;
	int		max;

	temp = info->stack_a;
	max = temp->index;
	while (temp)
	{
		if (temp->index > max)
			max = temp->index;
		temp = temp->next;
	}
	return (max);
}

static int	insert_big_value(t_info *info, int index_b)
{
	t_lst	*temp;
	int		i;

	temp = info->top_a;
	i = 0;
	while (temp->index != (index_b - 1))
	{
		i++;
		temp = temp->prev;
		if (!temp)
		{
			index_b--;
			temp = info->top_a;
			i = 0;
		}
	}
	i++;
	if (i <= (info->size_a - info->size_b) / 2)
		return (i);
	else
		return (i - (info->size_a - info->size_b));
}

static int	check_cost_a(t_info *info, int index_b)
{
	t_lst	*temp;
	int		i;
	int		max;

	temp = info->top_a;
	i = 0;
	max = fin_max_index(info);
	if (index_b > max)
		return (insert_big_value(info, index_b));
	while (temp->index != (index_b + 1))
	{
		i++;
		temp = temp->prev;
		if (!temp)
		{
			index_b++;
			temp = info->top_a;
			i = 0;
		}
	}
	if (i <= ((info->size_a - info->size_b) / 2))
		return (i);
	else
		return (i - (info->size_a - info->size_b));
}

void	set_cost(t_info *info)
{
	t_lst	*temp;
	int		i;

	temp = info->top_b;
	if (info->size_b == 0)
		info->size_b = info->size_a - 3;
	i = 0;
	while (i++ <= (info->size_b / 2))
	{
		temp->cost_a = check_cost_a(info, temp->index);
		temp->cost_b = (i - 1);
		temp = temp->prev;
	}
	temp = info->stack_b;
	i = 0;
	while (i++ < info->size_b / 2)
	{
		temp->cost_a = check_cost_a(info, temp->index);
		temp->cost_b = (i) * (-1);
		temp = temp->next;
	}
}
