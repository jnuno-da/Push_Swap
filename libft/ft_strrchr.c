/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <jnuno-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:00:13 by jnuno-da          #+#    #+#             */
/*   Updated: 2024/10/27 19:37:45 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (((char *)s)[i] != '\0')
	{
		i++;
	}
	while (i >= 0)
	{
		if (((char *)s)[i] == (char) c)
			return ((char *)(&s[i]));
		i--;
	}
	return (NULL);
}
/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	const char *str = "A tua prima de 4";
	int	c = 'a';

	
	const char *str1 = "A tua prima de 4";
	int	c1 = 'a';

	printf("Meu: %s\n", ft_strrchr(str, c));
	printf("Original: %s", strrchr(str1, c1));
}  */