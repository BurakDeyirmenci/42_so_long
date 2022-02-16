/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winmanager.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaramuk <mkaramuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:10:04 by mkaramuk          #+#    #+#             */
/*   Updated: 2022/02/15 15:01:53 by mkaramuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINMANAGER_H
# define WINMANAGER_H
# include "defines.h"

t_win	*init_win(char *map_path, char *title);
void	change_player_position(t_win *win, int x, int y);
void	change_player_side(t_win *win, t_side side);
int		on_destroy(void *param);
int		on_key_pressed(int keycode, void *param);

#endif