/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myutils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaramuk <mkaramuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:09:13 by mkaramuk          #+#    #+#             */
/*   Updated: 2022/02/26 09:21:52 by mkaramuk         ###   ########.fr       */
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
	ft_printf("%s\r", str);
	free(str);
	free(number);
}
