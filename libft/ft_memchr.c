/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <jnuno-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 22:18:42 by jnuno-da          #+#    #+#             */
/*   Updated: 2024/10/27 19:23:37 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	void *str = "A tua prima de 4";
	int	c = 'm';

	
	void *str1 = "A tua prima de 4";
	int	c1 = 'm';

	printf("Meu: %s\n", ft_memchr(str, c, 17));
	printf("Original: %s", memchr(str1, c1, 17));
}*/