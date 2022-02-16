/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myutils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaramuk <mkaramuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:09:13 by mkaramuk          #+#    #+#             */
/*   Updated: 2022/02/16 12:45:59 by mkaramuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "mlx.h"
#include "defines.h"
#include "consts.h"
#include "get_next_line.h"
#include "libft.h"

void	error(const char *msg, int errcode)
{
	ft_printf("Error\n%s\n", msg);
	exit(errcode);
}

void	print_move_count(t_win *win)
{
	char	*number;
	char	*str;
	int		i;

	str = ft_strdup("Move count: ");
	number = ft_itoa(win->player->move_count);
	i = 0;
	ft_strappend(&str, number);
	mlx_string_put(win->mlx, win->win, 10, 15, 0xf6f7f7, str);
	write(1, str, ft_strlen(str));
	write(1, "\r", 1);
	free(str);
	free(number);
}
