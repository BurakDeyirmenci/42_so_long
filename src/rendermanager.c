/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendermanager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaramuk <mkaramuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:58:33 by mkaramuk          #+#    #+#             */
/*   Updated: 2022/02/19 10:54:18 by mkaramuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "defines.h"
#include "myutils.h"
#include "mlx.h"
#include "rendermanager.h"

static void	__render_map_helper(t_win *win, char chr, int *x, int *y)
{
	if (chr == '1')
	{
		render_object(win, 0, *x, *y);
		*x += 64;
	}
	if (chr == 'C')
	{
		render_object(win, 1, *x, *y);
		*x += 64;
	}
	if (chr == 'P')
	{
		render_player(win, *x, *y);
		*x += 64;
	}
	if (chr == 'E')
	{
		render_object(win, 3, *x, *y);
		*x += 64;
	}
	if (chr == '0')
		*x += 64;
}

void	render_map(t_win *win)
{
	char	**map;
	int		line;
	int		col;
	int		x;
	int		y;

	line = -1;
	x = 0;
	y = 0;
	map = win->map->map;
	while (map[++line])
	{
		col = 0;
		while (map[line][col])
		{
			render_object(win, 2, x, y);
			__render_map_helper(win, map[line][col++], &x, &y);
		}
		y += 64;
		x = 0;
	}
	print_move_count(win);
}

void	render_object(t_win *win, int index, int x, int y)
{
	mlx_put_image_to_window(win->mlx, win->win, (win->objs + index)->img, x, y);
}

void	render_player(t_win *win, int x, int y)
{
	mlx_put_image_to_window(win->mlx, win->win, \
							win->player->cur_sprite->img, x, y);
	win->player->x = x;
	win->player->y = y;
}

void	render_end(t_win *win)
{
	char	*line1;
	char	*line2;

	line1 = "DON'T PANIC!";
	line2 = "You just won the game. Press ESC for exit.";
	mlx_clear_window(win->mlx, win->win);
	mlx_string_put(win->mlx, win->win, 50, win->height / 2, \
					0xFFFFFF, line1);
	mlx_string_put(win->mlx, win->win, \
					50, \
					win->height / 2 + 30, \
					0xFFFFFF, line2);
	print_move_count(win);
}
