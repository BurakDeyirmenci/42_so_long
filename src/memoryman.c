/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memoryman.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaramuk <mkaramuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:30:00 by mkaramuk          #+#    #+#             */
/*   Updated: 2022/02/19 09:02:14 by mkaramuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "memoryman.h"
#include "mlx.h"

void	free_win(t_win *win)
{
	int	i;

	i = 0;
	while (i < win->img_counter)
		mlx_destroy_image(win->mlx, win->objs[i++].img);
	free_map(win->map);
	free_player(win);
	free(win->objs);
	mlx_destroy_window(win->mlx, win->win);
	free(win);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
		free(map->map[i++]);
	free(map->map);
	free(map);
}

void	free_player(t_win *win)
{
	int	i;

	i = 0;
	while (win->player->sprites && i < 4)
	{
		if (win->player->sprites[i] && win->player->sprites[i]->img)
			mlx_destroy_image(win->mlx, win->player->sprites[i]->img);
		free(win->player->sprites[i++]);
	}
	free(win->player->sprites);
	free(win->player);
}
