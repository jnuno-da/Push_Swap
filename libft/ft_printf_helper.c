/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <jnuno-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 12:02:09 by jnuno-da          #+#    #+#             */
/*   Updated: 2024/12/14 15:59:57 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_upnbr(unsigned int n, int fd)
{
	unsigned long	nb;
	unsigned int	count;

	nb = n;
	count = 0;
	if (nb > 9)
	{
		count += ft_upnbr(nb / 10, fd);
		nb = nb % 10;
	}
	ft_putchar_fd(nb + 48, fd);
	return (count + 1);
}

int	ft_pnbr(int n, int fd)
{
	long	nb;
	int		count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = nb * -1;
		count++;
	}
	if (nb > 9)
	{
		count += ft_pnbr(nb / 10, fd);
		nb = nb % 10;
	}
	ft_putchar_fd(nb + 48, fd);
	count++;
	return (count);
}

int	ft_check_p(unsigned long n)
{
	int	count;

	count = 0;
	if (!n)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	count += 2;
	count += ft_base_hex(n, 'x');
	return (count);
}

int	ft_base_hex(unsigned long n, char format)
{
	unsigned int	count;
	const char		*base;

	count = 0;
	if (format == 'x')
		base = "0123456789abcdef";
	if (format == 'X')
		base = "0123456789ABCDEF";
	if (n < 16)
		count += write(1, &base[n], 1);
	if (n >= 16)
	{
		count += ft_base_hex(n / 16, format);
		count += ft_base_hex(n % 16, format);
	}
	return (count);
}
