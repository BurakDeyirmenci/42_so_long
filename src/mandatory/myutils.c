/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myutils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeyirme <rdeyirme@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:09:13 by mkaramuk          #+#    #+#             */
/*   Updated: 2022/05/11 11:50:31 by rdeyirme         ###   ########.fr       */
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

	str = ft_strdup("Move count: ");
	if (!str)
		return ;
	number = ft_itoa(win->player->move_count);
	if (!number)
	{
		free(str);
		return ;
	}
	ft_strappend(&str, number);
	mlx_string_put(win->mlx, win->win, 10, 15, 0xffffff, str);
	ft_printf("%s\r", str);
	free(str);
	free(number);
}
