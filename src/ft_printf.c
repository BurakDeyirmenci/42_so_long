/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaramuk <mkaramuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 22:57:40 by devman            #+#    #+#             */
/*   Updated: 2022/01/24 18:42:57 by mkaramuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_controller(char c, va_list args)
{
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putnbr_u(va_arg(args, unsigned int), \
		"0123456789"));
	else if (c == 'x')
		return (ft_putnbr_u(va_arg(args, unsigned int), \
		"0123456789abcdef"));
	else if (c == 'X')
		return (ft_putnbr_u(va_arg(args, unsigned int), \
		"0123456789ABCDEF"));
	else if (c == 's')
		return (ft_puts(va_arg(args, char *)));
	else if (c == 'c')
		return (ft_putchar((char)va_arg(args, int)));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'p')
	{
		ft_puts("0x");
		return (ft_putptr(va_arg(args, void *)) + 2);
	}
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		count;
	va_list	args;

	va_start(args, s);
	count = 0;
	while (*s)
	{
		if (*s == '%')
			count += ft_printf_controller(*++s, args);
		else
			count += ft_putchar(*s);
		s++;
	}
	va_end(args);
	return (count);
}
