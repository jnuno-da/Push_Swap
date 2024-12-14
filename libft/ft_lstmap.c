/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <jnuno-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 23:53:57 by jnuno-da          #+#    #+#             */
/*   Updated: 2024/11/02 14:30:35 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*new_node(void *content, void (*del)(void *), t_list *nlst)
{
	t_list	*temp;

	temp = ft_lstnew(content);
	if (!temp)
	{
		del(content);
		ft_lstclear(&nlst, del);
	}
	return (temp);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlst;
	t_list	*temp;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	nlst = NULL;
	while (lst)
	{
		content = f(lst->content);
		if (!content)
		{
			ft_lstclear(&nlst, del);
			return (NULL);
		}
		temp = new_node(content, del, nlst);
		if (!temp)
			return (NULL);
		ft_lstadd_back(&nlst, temp);
		lst = lst->next;
	}
	return (nlst);
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
void delete(void *content)
{
    free(content);
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