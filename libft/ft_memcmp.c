/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <jnuno-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:02:21 by jnuno-da          #+#    #+#             */
/*   Updated: 2024/10/27 19:44:03 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		i;
	char	*st1;
	char	*st2;

	st1 = (char *)s1;
	st2 = (char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while ((st1[i] == st2[i] && i + 1 < (int)n))
	{
		i++;
	}
	return (((unsigned char *)st1)[i] - ((unsigned char *)st2)[i]);
}
/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	char *a = "ppp";
	char *b = "ccc";
	int n = 3;
	printf("%i \n",ft_memcmp(a,b, n));
	printf("%i",memcmp(a,b, n));	
}*/