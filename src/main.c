/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeyirme <rdeyirme@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:29:01 by mkaramuk          #+#    #+#             */
/*   Updated: 2022/05/11 11:55:43 by rdeyirme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "mlx.h"
#include "consts.h"
#include "winmanager.h"
#include "rendermanager.h"

int	check_extension(char *str)
{
	char	*berex;
	int		i;
	int		j;

	i = 0;
	j = 0;
	berex = "reb.";
	while (str[++i])
		continue ;
	while (berex[j++] == str[--i])
		continue ;
	if (!berex[j - 1])
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_win	*win;

	if (argc < 2)
	{
		ft_printf("Error\nArguments aren't enough\n");
		return (ERRCODE_MISARGS);
	}
	if (!check_extension(argv[1]))
	{
		ft_printf("Error\nMap file extension must be .ber\n");
		return (ERRCODE_EXTENSION);
	}
	ft_printf("Game is loading....\n\n");
	win = init_win(argv[1], WIN_TITLE);
	render_map(win);
	mlx_hook(win->win, 2, 1L << 0, on_key_pressed, win);
	mlx_hook(win->win, 17, 0, on_destroy, win);
	mlx_loop(win->mlx);
	return (0);
}
