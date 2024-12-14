/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <jnuno-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:53:03 by jnuno-da          #+#    #+#             */
/*   Updated: 2024/10/26 02:05:47 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char str[50] = "Ai a minha vida";
	char str2[50] = "Ai a minha vida";

	printf("Antes do memset: %s\n",str);
	memset(str2, '$', 6);
	printf("Memset original: %s\n",str2);	
	ft_memset(str, '$', 6);
	printf("Meu memset: %s\n",str);
}*/