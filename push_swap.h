/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <jnuno-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:36:57 by jnuno-da          #+#    #+#             */
/*   Updated: 2025/03/07 01:06:02 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

// Stack
typedef struct s_lst
{
	int				value;
	int				index;
	struct s_lst	*next;
}				t_lst;

// Util functions
t_lst	*ft_lstnew(int value);
t_lst	*ft_lstlast(t_lst *head);
void	ft_lstadd_front(t_lst **stack, t_lst *new);
void	ft_lstadd_back(t_lst **stack, t_lst *new);
void	printlist(t_lst *head);
int		ft_lstsize(t_lst *head);
void	ft_error(char *msg);
void	ft_check_args(int argc, char **argv);
int		is_sorted(t_lst **stack);
int		get_distance(t_lst **stack, int index);
int		get_min(t_lst **stack, int val);
void	make_top(t_lst **stack, int distance);
void	free_stack(t_lst **stack);
void	ft_free(char **str);
long	ft_atol(const char *nptr);

// Algorithm utils
void	radix_sort(t_lst **stack_a, t_lst **stack_b);
void	simple_sort(t_lst **stack_a, t_lst **stack_b);
void	index_stack(t_lst **stack);
void	sort_3(t_lst **stack_a);
void	sort_4(t_lst **stack_a, t_lst **stack_b);
void	sort_5(t_lst **stack_a, t_lst **stack_b);

// Instruction functions
int		swap(t_lst **stack);
int		push(t_lst **stack_to, t_lst **stack_from);
int		rotate(t_lst **stack);
int		reverserotate(t_lst **stack);
int		sa(t_lst **stack_a);
int		sb(t_lst **stack_b);
int		ss(t_lst **stack_a, t_lst **stack_b);
int		pa(t_lst **stack_a, t_lst **stack_b);
int		pb(t_lst **stack_b, t_lst **stack_a);
int		ra(t_lst **stack_a);
int		rb(t_lst **stack_b);
int		rr(t_lst **stack_a, t_lst **stack_b);
int		rra(t_lst **stack_a);
int		rrb(t_lst **stack_b);
int		rrr(t_lst **stack_a, t_lst **stack_b);

#endif