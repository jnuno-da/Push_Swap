/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <jnuno-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:36:41 by jnuno-da          #+#    #+#             */
/*   Updated: 2024/11/01 00:14:05 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	size;

	size = ft_strlen(s) + 1;
	dup = (char *)malloc(size);
	if (!dup)
		return (NULL);
	else
		ft_memcpy (dup, s, size);
	return (dup);
}
/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char str1[]="456789";
	
	char str3[]="456789";
	

	printf("%s \n",ft_strdup(str1));
	
	printf("%s \n", strdup(str3));
} */
