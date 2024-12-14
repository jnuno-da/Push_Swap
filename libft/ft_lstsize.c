/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <jnuno-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:50:11 by jnuno-da          #+#    #+#             */
/*   Updated: 2024/11/01 15:54:47 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
/* int	main()
{
	t_list *st;
	t_list *st1;
	t_list *st2;
	char *a = "c";
	char *b = "d";
	char *c = "e";
	
	st = ft_lstnew((void *)a);
	st1 = ft_lstnew((void *)b);
	st2 = ft_lstnew((void *)c);
	
	st->next = st1;
	st1->next = st2;
	st2->next = NULL;

	st->next = st1;
	
	printf("%d",ft_lstsize(st));
	
} */
