/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <jnuno-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:21:13 by jnuno-da          #+#    #+#             */
/*   Updated: 2025/02/05 23:42:33 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cwords(const char *str, char c);
static char	**fill_index(const char *s, char c, char **str);
static void	*free_mem(char **str, int j);

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		size;
	int		i;

	i = 0;
	size = cwords(s, c);
	str = malloc(sizeof(char *) * (size + 1));
	if (!str)
		return (NULL);
	if (size > 0)
		fill_index(s, c, str);
	while (i < size)
	{
		if (str[i] == NULL)
		{
			free_mem (str, size);
			return (NULL);
		}
		i++;
	}
	str[size] = NULL;
	return (str);
}

static char	**fill_index(const char *s, char c, char **str)
{
	int	i;
	int	j;
	int	start;
	int	end;

	i = 0;
	j = 0;
	start = 0;
	end = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		if (s[start] == '\0')
			break ;
		while (s[i] && s[i] != c)
			i++;
		end = i;
		str[j] = ft_substr(s, start, end - start);
		j++;
	}
	str[j] = NULL;
	return (str);
}

static int	cwords(const char *str, char c)
{
	int	i;
	int	cw;

	i = 0;
	cw = 0;
	while (str[i] != '\0')
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			cw++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (cw);
}

void	*free_mem(char **str, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(str[i]);
		i++;
	}
	free (str);
	return (NULL);
}
/* int	main()
{
	int	i = 0;
	char *str = "";
	char **ss = ft_split(str, 'x');
	printf("%d\n",cwords(str, 'x'));
	while (ss[i])
	{
		printf("%s\n", ss[i]);
		i++;
	}
} */