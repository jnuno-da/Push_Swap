/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <jnuno-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:34:19 by jnuno-da          #+#    #+#             */
/*   Updated: 2024/10/27 17:37:56 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	size_t	i;

	i = 0;
	d = (char *)dst;
	s = (char *)src;
	if (!src && !dst)
		return (NULL);
	if (d > s)
	{
		while (len-- > 0)
		{
			d[len] = s[len];
		}
	}
	else
	{
		while (len-- > 0)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}
/* #include <string.h>
#include <stdio.h>

int	main(void)
{
    char str2 [50]="osj";
    char str1 [50]="osKBOimtHTYNIr3";

	printf("Source: %s\n",str1);
    ft_memmove(str2, str1, 5);
    printf("Dest: %s\n",str2);
	memmove(str2, str1, 5);
	printf("Dest original: %s\n", str2);
} */