/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <jnuno-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 23:12:17 by jnuno-da          #+#    #+#             */
/*   Updated: 2024/11/01 16:06:13 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	m;
	int	res;

	i = 0;
	m = 1;
	res = 0;
	while ((nptr[i] == 32) || (nptr[i] > 8 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			m = m * -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - 48);
		i++;
	}
	return (res * m);
}
/* #include <stdio.h>
#include <unistd.h>

int	main()
{
		printf("%i\n",(ft_atoi("214a7")));
		printf("original: %i", atoi("214a7"));
} */