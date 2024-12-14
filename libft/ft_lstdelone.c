/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <jnuno-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:02:46 by jnuno-da          #+#    #+#             */
/*   Updated: 2024/11/01 22:29:22 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	(*del)(lst->content);
	free(lst);
}
/*void ft_free(void *content)
{
	free(content);
}
 int main()
{
	t_list *st ;
	t_list *st1;
	t_list *st2;
	char *a = malloc(2);
    char *b = malloc(2);
    char *c = malloc(2);

	a[0] = 'c'; a[1] = '\0';
    b[0] = 'd'; b[1] = '\0';
    c[0] = 'e'; c[1] = '\0';
	
	st = ft_lstnew(a);
	st1 = ft_lstnew(b);
	st2 = ft_lstnew(c);

	st->next = st1;
	st1->next = st2;
	st2->next = NULL;
	
	t_list *temp = st;
	while (temp)
	{
		printf("Before: %s\n", (char *)temp->content);
		temp = temp->next;
	}
	ft_lstdelone(st1, &ft_free);
	temp = st;
	while (temp)
	{
		printf("after: %s\n", (char *)temp->content);
		temp = temp->next;
	}
	ft_lstdelone(st, &ft_free);
    ft_lstdelone(st2, &ft_free); 

	return 0;
} */