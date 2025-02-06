/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <jnuno-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:36:57 by jnuno-da          #+#    #+#             */
/*   Updated: 2025/02/06 00:28:22 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_lst
{
	int				value;
	int				index;
	int				cost_a;
	int				cost_b;
	struct s_lst	*prev;
	struct s_lst	*next;
}	t_lst;

typedef struct s_info
{
	t_lst	*stack_a;
	t_lst	*stack_b;
	t_lst	*top_a;
	t_lst	*top_b;
	int		size_a;
	int		size_b;
	int		pivo;
	int		max;
}	t_info;

int		count_args(char **argv, int argc);
int		*parse_split(char **argv, int argc);
int		count_args_split(char **argv);
int		*parse_input(char **argv, int argc);
int		*aux_input(int argc, char **argv);
void	free_split(char **split);
long	ft_atol(const char *nptr);
int		check_double_sign(char **argv);
int		check_number(char *argv);
int		check_error(char **argv);
int		check_for_duplicates(int *input, int list_size);
int		is_ordenated(int input_len, int *input);
void	init_stacks(t_info *info);
void	create_stacks(int *a, int list_size, t_info *info);
void	free_stacks(t_info *info);
void	find_max(t_info *info);
void	init_index(t_info *info);
void	case3(t_info *info);
void	swap_a(t_info *info);
void	swap_b(t_info *info);
void	swap_s(t_info *info);
void	push_a(t_info *info);
void	push_b(t_info *info);
void	push_swap(t_info *info);
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