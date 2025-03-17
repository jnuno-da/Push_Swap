/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <jnuno-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:59:22 by jnuno-da          #+#    #+#             */
/*   Updated: 2024/11/04 21:00:17 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*t;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		t = (*lst)->next;
		ft_lstdelone (*lst, del);
		*lst = t;
	}
}
/* void ft_free(void *node)
{
    free(node);   
}
int main() 
{
    t_list *st;
    char *a = malloc(1);
    char *b = malloc(1);
    char *c = malloc(1);

    a[0] = 'c'; 
    b[0] = 'd'; 
    c[0] = 'e'; 

    st = ft_lstnew(a);
    st->next = ft_lstnew(b);
    st->next->next = ft_lstnew(c);

   
    t_list *temp = st; 
    while (temp) 
	{
        printf("%s\n", (char *)temp->content);
        temp = temp->next;
    }
 
    ft_lstclear(&st, &ft_free);

    if (st == NULL) {
        printf("List cleared.\n");
    } else {
        printf("List not cleared.\n");
		temp = st; 
        while (temp) {
            printf("%s\n", (char *)temp->content);
            temp = temp->next;}
    }

    return 0;
} */