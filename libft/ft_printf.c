/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuno-da <jnuno-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:06:36 by jnuno-da          #+#    #+#             */
/*   Updated: 2024/12/14 15:59:45 by jnuno-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putch(char c, int fd)
{
	int	count;

	count = 0;
	write (fd, &c, 1);
	count++;
	return (count);
}

int	ft_puts(char *str, int fd)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		ft_putchar_fd (str[i], fd);
		i++;
	}
	return (i);
}

static int	p_args(va_list args, char opt)
{
	int	count;

	count = 0;
	if (opt == 'c')
		return (ft_putch(va_arg(args, int), 1));
	if (opt == 's')
		return (ft_puts(va_arg(args, char *), 1));
	if (opt == 'i' || opt == 'd')
		return (ft_pnbr(va_arg(args, int), 1));
	if (opt == 'u')
		return (ft_upnbr(va_arg(args, unsigned int), 1));
	if (opt == 'p')
		return (ft_check_p(va_arg(args, unsigned long)));
	if (opt == 'x')
		return (ft_base_hex(va_arg(args, unsigned int), 'x'));
	if (opt == 'X')
		return (ft_base_hex(va_arg(args, unsigned int), 'X'));
	if (opt == '%')
	{
		write(1, "%", 1);
		count = 1;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start (args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_putchar_fd(format[i], 1);
			count++;
		}
		else
		{
			i++;
			count += p_args(args, format[i]);
		}
		i++;
	}
	va_end(args);
	return (count);
}
