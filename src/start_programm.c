//
// Created by Hugor Chau on 2020-01-11.
//

#include "../incs/header.h"
#include <stdio.h>

void	open_window(t_window *ptr, char *name)
{
	(ptr)->x = SIZE_WINDOW_X;
	(ptr)->y = SIZE_WINDOW_Y;
	(ptr)->mlx = mlx_init();
	(ptr)->win = mlx_new_window((ptr)->mlx, (ptr)->x,
							 (ptr)->y, name);
}

void	manage_processes(t_full_image *full)
{
	draw(full);
	mlx_hook(full->ptr.win, 2, 0, key_press, full);
	mlx_hook(full->ptr.win, 17, 0, close_fractol, &full->ptr);
	mlx_hook(full->ptr.win, 4, 0, mouse_scroll, full);
	mlx_hook(full->ptr.win, 6, 0, mouse_motion, full);
	mlx_loop(full->ptr.mlx);
}

void	start_the_programm(t_fractal *fractal)
{
	t_full_image	full;
	t_window		ptr;

	open_window(&ptr, fractal->name);
	init_full(&full, ptr, fractal);
	manage_processes(&full);
}
