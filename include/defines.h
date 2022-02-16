/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaramuk <mkaramuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:52:23 by mkaramuk          #+#    #+#             */
/*   Updated: 2022/02/16 08:22:17 by mkaramuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

typedef void*	t_imgdata;
typedef void*	t_windata;
typedef void*	t_mlxdata;
typedef int		t_side;

typedef struct s_image
{
	int			x;
	int			y;
	t_imgdata	img;
}	t_image;

typedef struct s_player
{
	t_image	**sprites;
	t_side	side;
	t_image	*cur_sprite;
	int		move_count;
	int		x;
	int		y;
}	t_player;

typedef struct s_map
{
	int		w;
	int		h;
	char	**map;
}	t_map;

typedef struct s_win
{
	t_mlxdata	mlx;
	t_windata	win;
	int			width;
	int			height;
	int			img_counter;
	int			score;
	int			target_score;
	int			gameover;
	int			gateopen;
	t_map		*map;
	t_image		*objs;
	t_player	*player;
}	t_win;

#endif