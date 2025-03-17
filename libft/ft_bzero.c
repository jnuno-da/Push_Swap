/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <jnuno-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:54:52 by jnuno-da          #+#    #+#             */
/*   Updated: 2024/10/26 02:06:04 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int	c;

	c = '\0';
	ft_memset(s, c, n);
}
/*#include <stdio.h>
#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n > 0)
	{
		*p = c;
		p++;
		n--;
	}
	return (s);
}
int	main(void)
{
	char str[50] = "Ai a minha vida";
	char str2[50] = "Ai a minha vida";

	printf("Antes do bzero: %s\n",str);
	bzero(str2 + 2, 6);
	printf("bzero original: %s\n",str2);	
	ft_bzero(str + 2, 6);
	printf("Meu bzero: %s\n",str);
}*/