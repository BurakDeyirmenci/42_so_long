/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objectmanager.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaramuk <mkaramuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:17:07 by mkaramuk          #+#    #+#             */
/*   Updated: 2022/02/19 10:57:20 by mkaramuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTMANAGER_H
# define OBJECTMANAGER_H
# include "defines.h"

int		count_objs(t_map *map, char chr);
t_image	*create_player(t_win *win);
t_image	*create_object(t_win *win, char *relative_path);
t_image	*__create_player_helper(t_win *win, char *path);
t_image	*create_image_list(int count);

#endif