/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerman.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaramuk <mkaramuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 08:30:16 by mkaramuk          #+#    #+#             */
/*   Updated: 2022/02/16 10:03:44 by mkaramuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "playerman.h"

void	change_player_position(t_win *win, int x, int y)
{
	char		**map;
	char		*target_block;
	char		*source_block;

	map = win->map->map;
	source_block = &(map[win->player->y / 64][win->player->x / 64]);
	target_block = &(map[y / 64][x / 64]);
	if (*target_block == 'E' && win->gateopen)
	{	
		win->gameover = 1;
		win->player->move_count++;
	}
	if (*target_block == '0' || *target_block == 'C')
	{
		if (*target_block == 'C')
			win->score++;
		*target_block = 'P';
		*source_block = '0';
		win->player->x = x;
		win->player->y = y;
		win->player->move_count++;
	}
	if (win->target_score - win->score == 0)
		win->gateopen = 1;
}

void	change_player_side(t_win *win, t_side side)
{
	if (side == KEY_ARROW_LEFT || side == KEY_A)
		win->player->cur_sprite = win->player->sprites[2];
	else if (side == KEY_ARROW_RIGHT || side == KEY_D)
		win->player->cur_sprite = win->player->sprites[3];
	else if (side == KEY_ARROW_UP || side == KEY_W)
		win->player->cur_sprite = win->player->sprites[1];
	else if (side == KEY_ARROW_DOWN || side == KEY_S)
		win->player->cur_sprite = win->player->sprites[0];
	win->player->side = side;
}
