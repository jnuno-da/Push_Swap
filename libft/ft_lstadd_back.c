/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <jnuno-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:25:33 by jnuno-da          #+#    #+#             */
/*   Updated: 2024/11/01 17:02:05 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
/* int	main()
{
	t_list *st ;
	t_list *st1;
	t_list *st2;
	char *a = "c";
	char *b = "d";
	char *c = NULL;
	
	st = ft_lstnew((void *)a);
	st1 = ft_lstnew((void *)b);
	st2 = ft_lstnew((void *)c);

	st->next = st1;
	ft_lstadd_back(&st, st2);
	while (st)
	{
		if(st)
			printf("%s\n", (char *)st->content);
		else
				printf("NULL\n");
		st = st->next;
	}
}*/