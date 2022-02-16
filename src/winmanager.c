/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winmanager.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaramuk <mkaramuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:11:02 by mkaramuk          #+#    #+#             */
/*   Updated: 2022/02/16 09:34:04 by mkaramuk         ###   ########.fr       */
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

void	create_content(t_win *win)
{
	create_object(win, SP_OBJ_TREE);
	create_object(win, SP_OBJ_COIN);
	create_object(win, SP_OBJ_BACKGROUND);
	create_object(win, SP_OBJ_GATE);
	create_player(win);
}

t_win	*init_win(char *map_path, char *title)
{
	t_win	*ret;

	ret = malloc(sizeof(t_win));
	ret->map = read_map(map_path);
	if (!ret->map || !check_map(ret->map))
	{
		if (ret->map)
			free_map(ret->map);
		free(ret);
		error("Map couldn't read", ERRCODE_EXTENSION);
	}
	ret->mlx = mlx_init();
	ret->width = ret->map->w * 64;
	ret->height = ret->map->h * 64;
	ret->win = mlx_new_window(ret->mlx, ret->width, ret->height, title);
	ret->objs = create_image_list(4);
	ret->img_counter = 0;
	ret->gameover = 0;
	ret->gateopen = 0;
	ret->score = 0;
	ret->target_score = count_objs(ret->map, 'C');
	create_content(ret);
	return (ret);
}
