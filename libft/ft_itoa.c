/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <jnuno-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:02:54 by jnuno-da          #+#    #+#             */
/*   Updated: 2024/10/30 00:09:00 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digits(long nb)
{
	int	digits;

	digits = 0;
	if (nb <= 0)
	{
		if (nb == 0)
			return (1);
		nb = -nb;
		digits++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		len;
	char	*str;

	nb = n;
	len = digits(nb);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[len--] = (nb % 10) + 48;
		nb = nb / 10;
	}
	return (str);
}
/* int	main()
{
	int n = 123;
    char *result = ft_itoa(n);
    printf("Decimal number: %d, string conversion: %s\n", n, result);
    free(result);
}
 */