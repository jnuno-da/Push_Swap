/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_utils_f.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 11:41:04 by jnuno-da          #+#    #+#             */
/*   Updated: 2025/02/01 11:41:05 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_info *info, int rrr)
{
	t_lst	*temp;

	temp = info->stack_a;
	info->stack_a = info->stack_a->next;
	info->stack_a->prev = NULL;
	temp->next = NULL;
	temp->prev = info->top_a;
	info->top_a->next = temp;
	info->top_a = temp;
	if (!rrr)
		ft_putstr_fd("rra\n", 1);
}

void	reverse_rotate_b(t_info *info, int rrr)
{
	t_lst	*temp;

	temp = info->stack_b;
	info->stack_b = info->stack_b->next;
	info->stack_b->prev = NULL;
	temp->next = NULL;
	temp->prev = info->top_b;
	info->top_b->next = temp;
	info->top_b = temp;
	if (!rrr)
		ft_putstr_fd("rrb\n", 1);
}

void	reverse_rotate_r(t_info *info)
{
	reverse_rotate_a(info, 1);
	reverse_rotate_b(info, 1);
	ft_putstr_fd("rrr\n", 1);
}
