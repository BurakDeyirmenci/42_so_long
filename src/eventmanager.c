/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eventmanager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaramuk <mkaramuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 08:25:55 by mkaramuk          #+#    #+#             */
/*   Updated: 2022/02/23 12:32:20 by mkaramuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "defines.h"
#include "ft_printf.h"
#include "memoryman.h"
#include "winmanager.h"
#include "rendermanager.h"
#include "consts.h"
#include "mlx.h"

int	on_destroy(void *param)
{
	free_win((t_win *)param);
	ft_printf("\nBye...\n");
	exit(0);
}

int	on_key_pressed(int keycode, void *param)
{
	t_win	*win;

	win = (t_win *)param;
	if (keycode == KEY_ESCAPE)
		on_destroy(param);
	mlx_clear_window(win->mlx, win->win);
	if (keycode == KEY_ARROW_DOWN || keycode == KEY_S)
		change_player_position(win, win->player->x, win->player->y + 64);
	else if (keycode == KEY_ARROW_UP || keycode == KEY_W)
		change_player_position(win, win->player->x, win->player->y - 64);
	else if (keycode == KEY_ARROW_LEFT || keycode == KEY_A)
		change_player_position(win, win->player->x - 64, win->player->y);
	else if (keycode == KEY_ARROW_RIGHT || keycode == KEY_D)
		change_player_position(win, win->player->x + 64, win->player->y);
	change_player_side(win, keycode);
	if (win->gameover)
		render_end(win);
	else
		render_map(win);
	return (0);
}
