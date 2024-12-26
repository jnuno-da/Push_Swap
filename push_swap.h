/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <jnuno-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:36:57 by jnuno-da          #+#    #+#             */
/*   Updated: 2024/12/26 15:39:42 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

// Definição da estrutura da pilha
typedef struct s_stack {
    int *data;
    int top;
} stack;

// Declarações de funções
stack *initialize_stack();
int parse_arguments(int argc, char **argv, stack *a);
int is_valid_stack(stack *a);
int is_sorted(stack *a);
int stack_size(stack *a);
void free_stack(stack *s);

void swap(stack *s);
void push(stack *src, stack *dest);
void rotate(stack *s);
void reverse_rotate(stack *s);

void sort_stack(stack *a, stack *b);
void simple_sort(stack *a, stack *b);
void complex_sort(stack *a, stack *b);

#endif