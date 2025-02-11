/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 11:41:18 by jnuno-da          #+#    #+#             */
/*   Updated: 2025/02/01 11:41:20 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(t_info *info)
{
	info->stack_a = NULL;
	info->stack_b = NULL;
	info->top_a = NULL;
	info->top_b = NULL;
	info->size_a = 0;
	info->size_b = 0;
	info->pivo = 0;
	info->max = 0;
}

void	create_stacks(int *a, int list_size, t_info *info)
{
	int		i;
	t_lst	*new;
	t_lst	*prev;

	new = malloc(sizeof(t_lst));
	info->stack_a = new;
	info->size_a = list_size;
	prev = NULL;
	i = 0;
	while (i < list_size)
	{
		new->value = a[i];
		new->index = 0;
		new->next = NULL;
		new->prev = prev;
		if (i + 1 < list_size)
		{
			new->next = malloc(sizeof(t_lst));
			prev = new;
			new = new->next;
		}
		i++;
	}
	info->top_a = new;
}

void	find_max(t_info *info)
{
	t_lst	*temp;
	int		max;

	temp = info->stack_a;
	max = temp->value;
	while (temp)
	{
		if (temp->value > max)
			max = temp->value;
		temp = temp->next;
	}
	info->max = max;
}

void	init_index(t_info *info)
{
	t_lst	*temp;
	t_lst	*temp_min;
	int		index;
	int		min;

	find_max(info);
	temp = info->stack_a;
	temp_min = NULL;
	index = 1;
	while (index <= info->size_a)
	{
		min = info->max;
		while (temp)
		{
			if (temp->value <= min && temp->index == 0)
			{
				min = temp->value;
				temp_min = temp;
			}
			temp = temp->next;
		}
		temp_min->index = index;
		temp = info->stack_a;
		index++;
	}
}

void	case3(t_info *info)
{
	int	a;
	int	b;
	int	c;

	a = info->stack_a->value;
	b = info->stack_a->next->value;
	c = info->top_a->value;

	if (a > b && b < c && a < c)
		swap_a(info);
	else if (a > b && b > c)
	{
		swap_a(info);
		reverse_rotate_a(info, 0);
	}
	else if (a > b && b < c && a > c)
		rotate_a(info, 0);
	else if (a < b && b > c && a < c)
	{
		swap_a(info);
		rotate_a(info, 0);
	}
	else if (a < b && b > c && a > c)
		reverse_rotate_a(info, 0);
}
