/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaramuk <mkaramuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:18:23 by mkaramuk          #+#    #+#             */
/*   Updated: 2022/02/16 12:45:02 by mkaramuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"
#include "ft_printf.h"

int	ft_puts(const char *str)
{
	int	count;

	if (str == NULL)
		str = "(null)";
	count = 0;
	while (str && *str)
	{
		ft_putchar(*str++);
		count++;
	}
	return (count);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int nbr)
{
	int		count;

	count = 0;
	if (nbr == -2147483648)
	{
		count += ft_puts("-2");
		nbr = 147483648;
	}
	if (nbr < 0)
	{
		count += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr > 9)
		count += ft_putnbr(nbr / 10);
	count += ft_putchar((nbr % 10) + '0');
	return (count);
}

int	ft_putnbr_u(unsigned int nbr, char *base)
{
	int				count;
	unsigned int	base_len;

	count = 0;
	base_len = ft_strlen(base);
	if (nbr > (base_len - 1))
		count += ft_putnbr_u(nbr / base_len, base);
	count += ft_putchar(base[nbr % base_len]);
	return (count);
}

int	ft_putptr(void *ptr)
{
	unsigned long	p;
	int				count;

	count = 0;
	p = (unsigned long)ptr;
	if (p > 15)
		count += ft_putptr((void *)(p / 16));
	count += ft_putchar("0123456789abcdef"[p % 16]);
	return (count);
}
