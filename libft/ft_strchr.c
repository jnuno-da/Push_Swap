/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <jnuno-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:58:59 by jnuno-da          #+#    #+#             */
/*   Updated: 2024/10/27 19:39:36 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	return (ft_memchr(s, c, ft_strlen(s) + 1));
}
/* #include <stdio.h>
#include <string.h>
int	main(void)
{
	const char *str = "A tua prima de 4";
	int	c = 'm';

	
	const char *str1 = "A tua prima de 4";
	int	c1 = 'm';

	printf("Meu: %s\n", ft_strchr(str, c));
	printf("Original: %s", strchr(str1, c1));
} */