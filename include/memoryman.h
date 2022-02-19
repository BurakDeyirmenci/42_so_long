/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memoryman.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaramuk <mkaramuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:29:19 by mkaramuk          #+#    #+#             */
/*   Updated: 2022/02/19 09:44:28 by mkaramuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORYMAN_H
# define MEMORYMAN_H
# include "defines.h"

void	free_map(t_map *map);
void	free_player(t_win *win);
void	free_win(t_win *win);
void	free_objs(t_win *win);

#endif