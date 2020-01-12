//
// Created by Hugor Chau on 2020-01-11.
//

#include "../incs/header.h"
#include <stdio.h>

void	open_window(t_window **ptr, char *name)
{
	*ptr = (t_window *)malloc(sizeof(t_window));
	ft_bzero(*ptr, sizeof(t_window));
	(*ptr)->x = SIZE_WINDOW_X;
	(*ptr)->y = SIZE_WINDOW_Y;
	(*ptr)->mlx = mlx_init();
	(*ptr)->win = mlx_new_window((*ptr)->mlx, (*ptr)->x,
							 (*ptr)->y, name);
}

void	draw(t_full_image *full)
{
	mlx_clear_window(full->ptr->mlx, full->ptr->win);
	if (full->menu_on == TRUE)
	{
		mlx_put_image_to_window(full->ptr->mlx, full->ptr->win,
				full->menu->image, SIZE_WINDOW_X - SIZE_MENU, 0);
	}
}

void	manage_processes(t_full_image *full, t_fractal *fractal)
{
	draw(full);
	mlx_hook(full->ptr->win, 2, 0, key_press, full);
	mlx_hook(full->ptr->win, 17, 0, close_fractol, &full->ptr);
	mlx_hook(full->ptr->win, 4, 0, mouse_scroll, &full);
	mlx_loop(full->ptr->mlx);
}

void	start_the_programm(t_fractal *fractal)
{
	t_full_image	full;

	ft_putstr(fractal->name);
	open_window(&full.ptr, fractal->name);
	create_img(&full.menu, SIZE_MENU, SIZE_WINDOW_Y, full.ptr);
	fill_menu(&full.menu);
	full.menu_on = TRUE;
	manage_processes(&full, fractal);
}
