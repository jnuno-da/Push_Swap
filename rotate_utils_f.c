/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils_f.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 11:41:11 by jnuno-da          #+#    #+#             */
/*   Updated: 2025/02/01 11:41:13 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_info *info, int rr)
{
	t_lst	*temp;

	temp = info->stack_a;
	while (temp->next != info->top_a)
		temp = temp->next;
	temp->next = NULL;
	info->top_a->next = info->stack_a;
	info->top_a->prev = NULL;
	info->stack_a->prev = info->top_a;
	info->stack_a = info->top_a;
	info->top_a = temp;
	if (!rr)
		ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_info *info, int rr)
{
	t_lst	*temp;

	temp = info->stack_b;
	while (temp->next != info->top_b)
		temp = temp->next;
	temp->next = NULL;
	info->top_b->next = info->stack_b;
	info->top_b->prev = NULL;
	info->stack_b->prev = info->top_b;
	info->stack_b = info->top_b;
	info->top_b = temp;
	if (!rr)
		ft_putstr_fd("rb\n", 1);
}

void	rotate_r(t_info *info)
{
	rotate_a(info, 1);
	rotate_b(info, 1);
	ft_putstr_fd("rr\n", 1);
}
