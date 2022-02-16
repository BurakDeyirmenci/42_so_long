/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objectmanager.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaramuk <mkaramuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:17:07 by mkaramuk          #+#    #+#             */
/*   Updated: 2022/02/15 15:04:53 by mkaramuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTMANAGER_H
# define OBJECTMANAGER_H
# include "defines.h"

int		count_objs(t_map *map, char chr);
void	create_player(t_win *win);
int		create_object(t_win *win, char *relative_path);
t_image	*create_player_helper(t_win *win, char *path);
t_image	*create_image_list(int count);

#endif