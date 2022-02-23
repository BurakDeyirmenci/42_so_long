/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winmanager.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaramuk <mkaramuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:11:02 by mkaramuk          #+#    #+#             */
/*   Updated: 2022/02/23 11:54:16 by mkaramuk         ###   ########.fr       */
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

static void	__init_win_helper_freemap(t_win *win, int errcode, char *msg)
{
	free_map(win->map);
	free(win);
	error(msg, errcode);
}

static void	__init_win_helper_initmlx(t_win *win, char *title)
{
	win->mlx = mlx_init();
	if (!win->mlx)
		__init_win_helper_freemap(win, ERRCODE_MALLOC, ERRMSG_MALLOC);
	win->width = win->map->w * 64;
	win->height = win->map->h * 64;
	win->win = mlx_new_window(win->mlx, win->width, win->height, title);
	if (!win->win)
		__init_win_helper_freemap(win, ERRCODE_MALLOC, ERRMSG_MALLOC);
}

static int	__create_content_helper(t_win *win)
{
	int	i;

	i = 0;
	while (i < win->img_counter)
		if (!(win->objs[i++].img))
			return (1);
	if (!win->player)
		return (1);
	return (0);
}

void	create_content(t_win *win)
{
	create_object(win, SP_OBJ_TREE);
	create_object(win, SP_OBJ_COIN);
	create_object(win, SP_OBJ_BACKGROUND);
	create_object(win, SP_OBJ_GATE);
	create_player(win);
	if (__create_content_helper(win))
	{
		free_objs(win);
		free_player(win);
		mlx_destroy_window(win->mlx, win->win);
		__init_win_helper_freemap(win, ERRCODE_MALLOC, ERRMSG_MALLOC);
	}
}

t_win	*init_win(char *map_path, char *title)
{
	t_win	*ret;

	ret = malloc(sizeof(t_win));
	if (!ret)
		error(ERRMSG_MALLOC, ERRCODE_MALLOC);
	ret->map = read_map(map_path);
	if (!ret->map)
		__init_win_helper_freemap(ret, ERRCODE_MALLOC, ERRMSG_MALLOC);
	if (!check_map(ret->map))
		__init_win_helper_freemap(ret, ERRCODE_MAP, ERRMSG_MAP);
	__init_win_helper_initmlx(ret, title);
	ret->objs = create_image_list(4);
	if (!ret->objs)
	{
		mlx_destroy_window(ret->mlx, ret->win);
		__init_win_helper_freemap(ret, ERRCODE_MALLOC, ERRMSG_MALLOC);
	}
	ret->img_counter = 0;
	ret->gameover = 0;
	ret->gateopen = 0;
	ret->score = 0;
	ret->target_score = count_objs(ret->map, 'C');
	create_content(ret);
	return (ret);
}
