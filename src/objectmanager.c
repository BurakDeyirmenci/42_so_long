/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objectmanager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaramuk <mkaramuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:18:35 by mkaramuk          #+#    #+#             */
/*   Updated: 2022/02/19 10:57:20 by mkaramuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "defines.h"
#include "consts.h"
#include "mlx.h"

int	count_objs(t_map *map, char chr)
{
	int	line;
	int	col;
	int	count;

	line = 0;
	count = 0;
	while (map->map[line])
	{
		col = 0;
		while (map->map[line][col])
		{
			if (map->map[line][col] == chr)
				count++;
			col++;
		}
		line++;
	}
	return (count);
}

t_image	*create_image_list(int count)
{
	t_image	*ret;
	int		i;

	ret = malloc(sizeof(t_image) * count);
	if (!ret)
		return (NULL);
	i = 0;
	while (i < count)
	{
		(ret + (i))->img = NULL;
		(ret + (i))->x = 0;
		(ret + (i))->y = 0;
		i++;
	}
	return (ret);
}

t_image	*create_object(t_win *win, char *relative_path)
{
	int			h;
	int			w;
	t_image		*img;

	w = 64;
	h = 64;
	img = (win->objs + (win->img_counter++));
	img->img = mlx_xpm_file_to_image(win->mlx, relative_path, &w, &h);
	if (!img->img)
		return (NULL);
	img->y = 0;
	img->x = 0;
	return (img);
}

static t_image	*__create_player_helper(t_win *win, char *path)
{
	t_image	*img;
	int		w;
	int		h;

	w = 10;
	h = 10;
	img = malloc(sizeof(t_image));
	if (!img)
		return (NULL);
	img->img = mlx_xpm_file_to_image(win->mlx, path, &w, &h);
	if (!img->img)
	{
		free(img);
		return (NULL);
	}
	img->x = 0;
	img->y = 0;
	return (img);
}

t_player	*create_player(t_win *win)
{
	win->player = malloc(sizeof(t_player));
	if (!win->player)
		return (NULL);
	win->player->sprites = malloc(sizeof(t_image *) * 4);
	if (!win->player->sprites)
	{
		free(win->player);
		win->player = NULL;
		return (NULL);
	}
	win->player->x = 0;
	win->player->y = 0;
	win->player->move_count = 0;
	win->player->side = KEY_ARROW_DOWN;
	win->player->sprites[0] = __create_player_helper(win, SP_PLAYER_DOWN);
	win->player->sprites[1] = __create_player_helper(win, SP_PLAYER_UP);
	win->player->sprites[2] = __create_player_helper(win, SP_PLAYER_LEFT);
	win->player->sprites[3] = __create_player_helper(win, SP_PLAYER_RIGHT);
	win->player->cur_sprite = win->player->sprites[0];
	return (win->player);
}
