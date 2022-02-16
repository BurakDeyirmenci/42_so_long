/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapmanager.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaramuk <mkaramuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:13:29 by mkaramuk          #+#    #+#             */
/*   Updated: 2022/02/15 15:06:57 by mkaramuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPMANAGER_H
# define MAPMANAGER_H
# include "defines.h"

t_map	*create_empty_map(void);
t_map	*read_map(char *path);
void	print_map(t_win *win);
int		check_map(t_map *map);

#endif