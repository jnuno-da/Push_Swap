/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_back.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 11:40:32 by jnuno-da          #+#    #+#             */
/*   Updated: 2025/02/01 11:40:34 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	total_cost(int a, int b)
{
	if (a > 0 && b > 0)
	{
		if (a > b)
			return (a);
		else
			return (b);
	}
	if (a < 0 && b < 0)
	{
		if (a < b)
			return (ft_abs(a));
		else
			return (ft_abs(b));
	}
	return (ft_abs(a) + ft_abs(b));
}

static t_lst	*choose_push_back(t_info *info)
{
	t_lst	*temp;
	t_lst	*push;
	int		min_cost;
	int		temp_cost;

	temp = info->top_b->prev;
	push = info->top_b;
	min_cost = total_cost(push->cost_a, push->cost_b);
	while (temp)
	{
		temp_cost = total_cost(temp->cost_a, temp->cost_b);
		if (temp_cost < min_cost)
		{
			push = temp;
			min_cost = temp_cost;
		}
		temp = temp->prev;
	}
	return (push);
}

static int	handle_stack_b(t_info *info, t_lst *target, int i)
{
	if (target->cost_b > 0)
	{
		if (target->cost_a > 0 && i < target->cost_a)
		{
			rotate_r(info);
			return (1);
		}
		rotate_b(info, 0);
		return (0);
	}
	if (target->cost_a < 0 && i < ft_abs(target->cost_a))
	{
		reverse_rotate_r(info);
		return (1);
	}
	reverse_rotate_b(info, 0);
	return (0);
}

void	push_back(t_info *info)
{
	t_lst	*target;
	int		i;

	set_cost(info);
	target = choose_push_back(info);
	i = 0;
	while (info->top_b != target)
		i = i + handle_stack_b(info, target, i);
	while (i < ft_abs(target->cost_a))
	{
		if (target->cost_a > 0)
			rotate_a(info, 0);
		else
			reverse_rotate_a(info, 0);
		i++;
	}
	push_a(info);
	info->size_b--;
}
