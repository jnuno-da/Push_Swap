/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <jnuno-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 23:12:59 by jnuno-da          #+#    #+#             */
/*   Updated: 2024/11/01 23:51:54 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/* void	ft_upstring(void *c)
{
	int	i = 0;
	char *str = c;
	while(str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
				    str[i] -= 32;
		i++;
	}
}
int main()
{
	
	t_list *st ;
	t_list *st1;
	t_list *st2;
	
	char *a = ft_strdup("a");
    char *b = ft_strdup("b");
    char *c = ft_strdup("c");
	
	st = ft_lstnew(a);
	st1 = ft_lstnew(b);
	st2 = ft_lstnew(c);

	st->next = st1;
	st1->next = st2;
	st2->next = NULL;
	
	t_list *t = st;
	while (t)
	{
		printf("Before > %s\n", (char *)t->content);
		t = t->next;
	}
	ft_lstiter(st, ft_upstring);
	t = st;
	while (t)
    {
        printf("After > %s\n", (char *)t->content);
        t = t->next;           
    }
} */