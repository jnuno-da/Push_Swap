/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <jnuno-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:36:57 by jnuno-da          #+#    #+#             */
/*   Updated: 2025/01/29 01:11:20 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>

typedef struct f_list
{
	int	value;
	int	index;
	int	cost_a;
	int	cost_b;
	struct f_list	*prev;
	struct f_list	*next;
}	g_list;

typedef struct s_info
{
	g_list *stack_a;
	g_list *stack_b;
	g_list *top_a;
	g_list *top_b;
	int		size_a;
	int		size_b;
	int 	pivo;
	int		max;
}	t_info;

int		check_number(char *argv);
int		check_error(char **argv);
int		*check_for_duplicates(int *input, char **argv, int list_size);
int		is_ordenated(int input_len, int *input);
void	init_stacks(t_info *info);
void	create_stacks(int *a, int list_size, t_info *info);
void	find_max(t_info *info);
void	init_index(t_info *info);
void	case3(t_info *info);
void	swap_a(t_info *info);
void	swap_b(t_info *info);
void	swap_s(t_info *info);
void	push_a(t_info *info);
void	push_b(t_info *info);
void	rotate_a(t_info *info, int rr);
void	rotate_b(t_info *info, int rr);
void	rotate_r(t_info *info);
void	reverse_rotate_a(t_info *info, int rrr);
void	reverse_rotate_b(t_info *info, int rrr);
void	reverse_rotate_r(t_info *info);
int		ft_abs(int i);
int		fin_max_index(t_info *info);
void	set_cost(t_info *info);
void	bigger_stacks(t_info *info);
void	push_back(t_info *info);

#endif