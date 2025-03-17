/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <jnuno-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:09:44 by jnuno-da          #+#    #+#             */
/*   Updated: 2024/11/01 16:24:38 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*t;

	if (!lst)
		return (NULL);
	t = lst;
	while (t->next)
		t = t->next;
	return (t);
}
/* int	main()
{
	t_list *st;
	t_list *st1;
	t_list *st2;
	t_list *last;
	char *a = "c";
	char *b = "d";
	char *c = "e";
	
	st = ft_lstnew(a);
	st1 = ft_lstnew(b);
	st2 = ft_lstnew(c);
	
	st->next = st1;
	st1->next = st2;
	st2->next = NULL;

	last = ft_lstlast(st);
	if(last)
		printf("%s",(char *)last->content);
}  */