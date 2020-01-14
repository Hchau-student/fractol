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
	draw_fractal(full);
//	if (full->fractal.rotate != 0)
//		rotate_all(&(full->z_matrix), full->rotation);
//	img_from_matrix(&full->drawing, full->z_matrix);
	mlx_put_image_to_window(full->ptr->mlx, full->ptr->win,
							full->drawing->image, 0, 0);
	mlx_put_image_to_window(full->ptr->mlx, full->ptr->win,
							full->patrick->image, 0, 0);
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
	mlx_hook(full->ptr->win, 4, 0, mouse_scroll, full);
	mlx_hook(full->ptr->win, 6, 0, mouse_motion, full);
	mlx_loop(full->ptr->mlx);
}

void	start_the_programm(t_fractal *fractal)
{
	t_full_image	full;

	open_window(&full.ptr, fractal->name);
	/*
	**		вынести подготовку фулла в другую функцию
	*/
	create_img(&full.menu, SIZE_MENU, SIZE_WINDOW_Y, full.ptr);
	create_img(&full.drawing, SIZE_WINDOW_X, SIZE_WINDOW_Y, full.ptr);
	fill_menu(&full.menu);
	full.big_patrick = (t_image *)malloc(sizeof(t_image));
	full.patrick = (t_image *)malloc(sizeof(t_image));
	full.patrick->mlx_ptr = full.ptr->mlx;
	full.big_patrick->mlx_ptr = full.ptr->mlx;
	open_image(&full.patrick, "./norm1.xpm", SIZE_WINDOW_X, SIZE_WINDOW_Y);
	open_image(&full.big_patrick, "./большой_патрик.xpm", SIZE_WINDOW_X, SIZE_WINDOW_Y);
	full.menu_on = TRUE;
	full.fractal = *fractal;
	/*
	**
	*/
	manage_processes(&full, fractal);
}
