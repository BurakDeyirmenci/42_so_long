/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapmanager.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaramuk <mkaramuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:18:06 by mkaramuk          #+#    #+#             */
/*   Updated: 2022/02/21 19:40:41 by mkaramuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "ft_printf.h"
#include "mapmanager.h"
#include "memoryman.h"
#include "get_next_line.h"
#include "libft.h"

t_map	*create_empty_map(void)
{
	t_map	*ret;

	ret = malloc(sizeof(t_map));
	if (!ret)
		return (ret);
	ret->h = 0;
	ret->w = 0;
	ret->map = NULL;
	return (ret);
}

static	char	*read_file(char *path)
{
	char	*ret;
	char	*line;
	int		fd;

	ret = NULL;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_strappend(&ret, line);
		free(line);
	}
	close(fd);
	return (ret);
}

t_map	*read_map(char *path)
{
	t_map	*ret;
	char	*map;

	map = read_file(path);
	if (!map)
		return (NULL);
	ret = create_empty_map();
	if (!ret)
	{
		free(map);
		return (NULL);
	}
	ret->map = ft_split(map, '\n');
	if (!ret->map)
	{
		free(map);
		free_map(ret);
		return (NULL);
	}
	while (ret->map[ret->h])
		ret->h++;
	ret->w = ft_strlen(ret->map[0]);
	free(map);
	return (ret);
}

void	print_map(t_win *win)
{
	char	**map;

	ft_printf("\n");
	map = win->map->map;
	while (*map)
		ft_printf("%s\n", *map++);
	ft_printf("\n");
}
