/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 11:39:36 by jnuno-da          #+#    #+#             */
/*   Updated: 2025/02/01 11:39:38 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_info *info)
{
	t_lst	*temp;
	int		swapv;
	int		swapi;

	temp = info->stack_a;
	while (temp->next != info->top_a)
		temp = temp->next;
	swapv = temp->value;
	swapi = temp->index;
	temp->value = info->top_a->value;
	temp->index = info->top_a->index;
	info->top_a->value = swapv;
	info->top_a->index = swapi;
	ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_info *info)
{
	t_lst	*temp;
	int		swapv;
	int		swapi;

	temp = info->stack_b;
	while (temp->next != info->top_b)
		temp = temp->next;
	swapv = temp->value;
	swapi = temp->index;
	temp->value = info->top_b->value;
	temp->index = info->top_b->index;
	info->top_b->value = swapv;
	info->top_b->index = swapi;
	ft_putstr_fd("sb\n", 1);
}

void	swap_s(t_info *info)
{
	swap_a(info);
	swap_b(info);
	ft_putstr_fd("ss\n", 1);
}

long	ft_atol(const char *nptr)
{
	long	res;
	long	m;
	int		i;

	i = 0;
	m = 1;
	res = 0;
	while ((nptr[i] == 32) || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			m = m * -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - 48);
		i++;
	}
	return (res * m);
}
