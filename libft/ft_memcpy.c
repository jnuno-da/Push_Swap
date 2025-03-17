/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <jnuno-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:02:41 by jnuno-da          #+#    #+#             */
/*   Updated: 2024/10/27 17:28:12 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	i = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char str1[]="456789";
	char str2[]="2146";
	char str3[]="456789";
	char str4[]="2146";

	memcpy(str1, str2, 4);
	printf("%s \n", str1);
	ft_memcpy(str3, str4, 4);
	printf("%s \n", str3);
}*/