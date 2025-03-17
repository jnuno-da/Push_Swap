/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <jnuno-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:53:08 by jnuno-da          #+#    #+#             */
/*   Updated: 2024/10/27 15:48:04 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		tsize;
	char	*str;

	i = -1;
	if (!s1 || !s2)
		return (0);
	tsize = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	str = (char *)malloc(tsize + 1);
	if (!str)
		return (NULL);
	while (s1[++i] != '\0')
	{
		str[i] = s1[i];
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i++] = s2[j++];
	}
	str[i] = '\0';
	return (str);
}
/* 
 int	main()
{
	char *s1 = "Ola";
	char *s2 = "piu";
	char *result = ft_strjoin(s1,s2);
	printf("%s", result);
	free(result);
} */