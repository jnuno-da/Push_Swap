/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <jnuno-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:55:08 by jnuno-da          #+#    #+#             */
/*   Updated: 2024/10/29 21:47:49 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(""));
	i = 0;
	j = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (j > i && ft_strchr(set, s1[j - 1]))
		j--;
	return (ft_substr(s1, i, (j - i)));
}
/* int	main(void)
{
	const char	*s1 = "aaaaabbbbbgood luckbbbbbaaaa";
	const char	*set = "ab";

	char	*trim = ft_strtrim(s1, set);

		printf("string: %s\n", s1);
		printf("string cortada: %s\n", trim);
		free(trim);
	return(0);
} */