/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <jnuno-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:51:41 by jnuno-da          #+#    #+#             */
/*   Updated: 2024/10/27 21:53:07 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;
	char		*src;
	char		*str;

	src = (char *)little;
	str = (char *)big;
	i = 0;
	j = 0;
	if (!big && !len)
		return (0);
	if (!little[j])
		return ((char *)big);
	while (str[i] && i < len)
	{
		while (str[i + j] == src[j] && str[i + j] && i + j < len)
		{
			j++;
			if (src[j] == 0)
				return ((char *)big + i);
		}
		j = 0;
		i++;
	}
	return (0);
}
/* #include <stdio.h>
#include <string.h>
int	main(void)
{
	const char *str = "";
	const char *c = "";
	
	const char *str1 = "";
	const char *c1 = "";
	
	printf("Meu: %s\n", ft_strnstr(str, c, 5));
	printf("Original: %s", strnstr(str1, c1, 5));
} */