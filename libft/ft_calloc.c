/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <jnuno-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:07:54 by jnuno-da          #+#    #+#             */
/*   Updated: 2024/10/27 11:48:58 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = malloc(nmemb * size);
	if (! ptr)
		return (NULL);
	while (i < nmemb * size)
	{
		ptr[i++] = 0;
	}
	return (ptr);
}
/*int	 main()
{
	
	char *a = ft_calloc(4, 4);
	free(a);
}*/