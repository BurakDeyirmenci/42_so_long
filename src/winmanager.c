/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winmanager.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaramuk <mkaramuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:11:02 by mkaramuk          #+#    #+#             */
/*   Updated: 2022/02/19 09:07:06 by mkaramuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "memoryman.h"
#include "myutils.h"
#include "mlx.h"
#include "rendermanager.h"
#include "mapmanager.h"
#include "consts.h"
#include "objectmanager.h"
#include "winmanager.h"

void	__init_win_helper_freemap(t_win *win)
{
	if (win->map)
		free_map(win->map);
	free(win);
	error(ERRMSG_MALLOC, ERRCODE_MALLOC);
}

void	__init_win_helper_initmlx(t_win *win, char *title)
{
	win->mlx = mlx_init();
	if (!win->mlx)
		__init_win_helper_freemap(win);
	win->width = win->map->w * 64;
	win->height = win->map->h * 64;
	win->win = mlx_new_window(win->mlx, win->width, win->height, title);
	if (!win->win)
		__init_win_helper_freemap(win);
}

void	create_content(t_win *win)
{
	int	i;

	i = 0;
	if (!create_object(win, SP_OBJ_TREE) || \
		!create_object(win, SP_OBJ_COIN) || \
		!create_object(win, SP_OBJ_BACKGROUND) || \
		!create_object(win, SP_OBJ_GATE) || \
		!create_player(win))
	{
		while (i < win->img_counter)
			mlx_destroy_image(win->mlx, win->objs[i++].img);
		free_player(win);
		mlx_destroy_window(win->mlx, win->win);
		__init_win_helper_freemap(win);
	}
}

t_win	*init_win(char *map_path, char *title)
{
	t_win	*ret;

	ret = malloc(sizeof(t_win));
	if (!ret)
		return (NULL);
	ret->map = read_map(map_path);
	if (!ret->map || !check_map(ret->map))
		__init_win_helper_freemap(ret);
	__init_win_helper_initmlx(ret, title);
	ret->objs = create_image_list(4);
	if (!ret->objs)
	{
		mlx_destroy_window(ret->mlx, ret->win);
		__init_win_helper_freemap(ret);
	}
	ret->img_counter = 0;
	ret->gameover = 0;
	ret->gateopen = 0;
	ret->score = 0;
	ret->target_score = count_objs(ret->map, 'C');
	create_content(ret);
	return (ret);
}
