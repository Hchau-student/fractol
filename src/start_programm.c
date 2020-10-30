/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_programm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:13:57 by hchau             #+#    #+#             */
/*   Updated: 2020/02/10 14:14:04 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/header.h"
#include <stdio.h>

int			close_fractol(t_full_image *param)
{
	free_img(&param->fractal.drawing, SIZE_WINDOW_Y * SIZE_WINDOW_X * 4);
	free(param->fractal.drawing);
	free_img(&param->menu.drawing, SIZE_WINDOW_Y * SIZE_MENU * 4);
	free(param->menu.drawing);
	free_img(&param->patrick.drawing, param->patrick.dr_size);
	free(param->patrick.drawing);
	free_img(&param->patrick.drawing2, param->patrick.nxt_dr_size);
	free(param->patrick.drawing2);
	free_img(&param->patrick.backgrownd, 1400 * 926 * 4);
	free(param->patrick.backgrownd);
	free_img(&param->patrick.stars, param->patrick.stars_size);
	free(param->patrick.stars);
	mlx_clear_window(param->ptr.mlx, param->ptr.win);
	mlx_destroy_window(param->ptr.mlx, param->ptr.win);
	exit(0);
	return (0);
}

int			key_exit(int keycode, t_full_image *param)
{
	if (keycode == ESCAPE)
	{
		if (param->patrick.on != FAULSE)
			system("pkill afplay");
		close_fractol(param);
	}
	return (0);
}

void		open_window(t_window *ptr, char *name)
{
	(ptr)->x = SIZE_WINDOW_X;
	(ptr)->y = SIZE_WINDOW_Y;
	(ptr)->mlx = mlx_init();
	(ptr)->win = mlx_new_window((ptr)->mlx, (ptr)->x,
							(ptr)->y, name);
}

void		manage_processes(t_full_image *full)
{
	draw(full);
	mlx_hook(full->ptr.win, 2, 0, key_press, full);
	mlx_hook(full->ptr.win, 17, 0, close_fractol, full);
	mlx_hook(full->ptr.win, 4, 0, mouse_scroll, full);
	mlx_hook(full->ptr.win, 6, 0, mouse_motion, full);
	mlx_loop(full->ptr.mlx);
}

void		start_the_programm(t_fractal *fractal)
{
	t_full_image	full;
	t_window		ptr;

	open_window(&ptr, fractal->name);
	init_full(&full, ptr, fractal);
	manage_processes(&full);
}
