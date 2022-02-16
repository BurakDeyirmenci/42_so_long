/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerman.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaramuk <mkaramuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 08:30:34 by mkaramuk          #+#    #+#             */
/*   Updated: 2022/02/16 08:31:49 by mkaramuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYERMAN_H
# define PLAYERMAN_H
# include "defines.h"
# include "consts.h"

void	change_player_position(t_win *win, int x, int y);
void	change_player_side(t_win *win, t_side side);
#endif