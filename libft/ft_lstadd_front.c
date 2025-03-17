/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <jnuno-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:38:39 by jnuno-da          #+#    #+#             */
/*   Updated: 2024/11/01 23:51:42 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
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
	ft_lstadd_front(&st, st2);
	while (st2)
	{
		printf("%s", (char *)st2->content);
		st2 = st2->next;
	}
} */