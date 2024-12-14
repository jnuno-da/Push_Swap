/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <jnuno-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:58:27 by jnuno-da          #+#    #+#             */
/*   Updated: 2024/10/26 02:05:46 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d_len;
	size_t	s_len;

	i = 0;
	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (size == 0)
		return (s_len);
	if (size < d_len)
		return (s_len + size);
	while (src[i] && ((d_len + i) < (size - 1)))
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (d_len + s_len);
}
/*
#include <stdio.h>
#include <strings.h>

int     main(void)
{
		char *src = "Ai a minha vida";
		char *dest = "Ola Mae";
		int  size = 6;

	printf("meu: %zu\n", ft_strlcat(dest,src,size));

}*/