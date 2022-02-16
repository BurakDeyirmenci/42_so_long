/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendermanager.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaramuk <mkaramuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:03:16 by mkaramuk          #+#    #+#             */
/*   Updated: 2022/02/16 08:29:30 by mkaramuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERMANAGER_H
# define RENDERMANAGER_H
# include "defines.h"

void	render_object(t_win *win, int index, int x, int y);
void	render_player(t_win *win, int x, int y);
void	render_map(t_win *win);
void	render_end(t_win *win);

#endif