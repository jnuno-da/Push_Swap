/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 11:40:49 by jnuno-da          #+#    #+#             */
/*   Updated: 2025/02/01 11:40:50 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	delete_b(t_info *info)
{
	t_lst	*temp;

	temp = info->stack_b;
	while (temp->next != info->top_b && temp->next != NULL)
		temp = temp->next;
	if (temp->next == NULL)
	{
		info->stack_b = NULL;
		info->top_b = NULL;
		return ;
	}
	temp->next = NULL;
	info->top_b = temp;
}

void	push_a(t_info *info)
{
	t_lst	*temp;

	temp = info->stack_a;
	if (info->stack_b == NULL)
		return ;
	if (temp == NULL)
	{
		info->stack_a = info->stack_b;
		info->stack_a->prev = NULL;
		info->top_a = info->stack_a;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = info->top_b;
		temp->next->prev = temp;
		info->top_a = info->top_b;
	}
	delete_b(info);
	ft_putstr_fd("pa\n", 1);
}

static void	delete_a(t_info *info)
{
	t_lst	*temp;

	temp = info->stack_a;
	while (temp->next != info->top_a)
		temp = temp->next;
	temp->next = NULL;
	info->top_a = temp;
}

void	push_b(t_info *info)
{
	t_lst	*temp;

	temp = info->stack_b;
	if (info->stack_a == NULL)
		return ;
	if (temp == NULL)
	{
		info->stack_b = info->top_a;
		info->stack_b->prev = NULL;
		info->top_b = info->stack_b;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = info->top_a;
		temp->next->prev = temp;
		info->top_b = info->top_a;
	}
	delete_a(info);
	ft_putstr_fd("pb\n", 1);
}
