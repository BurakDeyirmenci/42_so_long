/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaramuk <mkaramuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 23:16:04 by devman            #+#    #+#             */
/*   Updated: 2022/02/16 12:43:06 by mkaramuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

int	ft_puts(const char *str);
int	ft_putchar(char c);
int	ft_putnbr(int nbr);
int	ft_putnbr_u(unsigned int nbr, char *base);
int	ft_putptr(void *ptr);
int	ft_printf(const char *s, ...);

#endif