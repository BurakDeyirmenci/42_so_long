/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchekcer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaramuk <mkaramuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:14:10 by mkaramuk          #+#    #+#             */
/*   Updated: 2022/02/16 09:02:18 by mkaramuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
#include "objectmanager.h"
#include "defines.h"

static int	check_map_helper_rectangle(t_map *map)
{
	char	**cmap;
	int		x;
	int		y;
	size_t	ref;

	x = 0;
	y = 0;
	cmap = map->map;
	ref = ft_strlen(cmap[x]);
	while (cmap[x])
	{
		if (ft_strlen(cmap[x]) != ref)
			return (0);
		x++;
	}
	if (x == 1)
		return (0);
	return (1);
}

static int	check_map_helper_wall(t_map *map, int x, int y)
{
	char	**cmap;
	int		i;

	i = 0;
	cmap = map->map;
	while (cmap[y])
	{	
		if (cmap[y++][x] != '1')
			return (0);
	}
	return (1);
}

static int	check_map_helper_updown(t_map *map, int x, int y)
{
	char	**cmap;
	int		i;

	i = 0;
	cmap = map->map;
	while (cmap[y][x])
	{
		if (cmap[y][x++] != '1')
			return (0);
	}
	return (1);
}

static int	check_map_helper(t_map *map)
{
	char	**cmap;
	int		i;

	cmap = map->map;
	if (!check_map_helper_wall(map, 0, 0) || \
		!check_map_helper_wall(map, map->w - 1, 0) || \
		!check_map_helper_updown(map, 0, 0) || \
		!check_map_helper_updown(map, 0, map->h - 1) || \
		!check_map_helper_rectangle(map))
		return (0);
	i = 0;
	return (1);
}

int	check_map(t_map *map)
{
	char	**cmap;
	int		x;
	int		y;
	int		e_count;
	int		p_count;

	x = 0;
	y = 0;
	cmap = map->map;
	e_count = count_objs(map, 'E');
	p_count = count_objs(map, 'P');
	if (e_count == 0 || e_count > 1 || \
		p_count == 0 || p_count > 1 || count_objs(map, 'C') == 0)
		return (0);
	while (cmap[y])
	{
		x = 0;
		while (cmap[y][x])
			if (!ft_strchr("01PEC", cmap[y][x++]))
				return (0);
		y++;
	}
	if (!check_map_helper(map))
		return (0);
	return (1);
}
