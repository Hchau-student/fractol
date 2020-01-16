//
// Created by Hugor Chau on 2020-01-15.
//
#include "../incs/header.h"

void	write_rest_menu(t_draw_menu *menu, t_window *ptr)
{
	mlx_string_put(ptr->mlx, ptr->win, 900, 100,
				   0x00FFFFFF, "Mouse:");
	mlx_string_put(ptr->mlx, ptr->win, 870, 140,
				   0x00BBBBFF, "zoom:");
	mlx_string_put(ptr->mlx, ptr->win, 900, 300,
				   0x00FFFFFF, "Buttons:");
	mlx_string_put(ptr->mlx, ptr->win, 870, 340,
				   0x00BBBBFF, "moving mode:");
	mlx_string_put(ptr->mlx, ptr->win, 870, 360,
				   0x00BBBBFF, "enter - on/off");
	mlx_string_put(ptr->mlx, ptr->win, 870, 400,
				   0x00BBBBFF, "menu:");
	mlx_string_put(ptr->mlx, ptr->win, 870, 420,
				   0x00BBBBFF, "h - close/open");
	mlx_string_put(ptr->mlx, ptr->win, 870, 460,
				   0x00BBBBFF, "change color:");
}


void	current_menu(t_draw_menu *menu, t_window *ptr, t_full_image *full)
{
	if (full->patrick.on)
	{
		mlx_string_put(ptr->mlx, ptr->win, 870, 160,
					   0x00BBBBFF, "torn the meme mode!");
		mlx_string_put(ptr->mlx, ptr->win, 870, 480,
					   0x00BBBBFF, "torn the meme mode!");
		mlx_string_put(ptr->mlx, ptr->win, 870, 740,
					   0x00BBBBFF, "press g");
	}
	else
	{
		mlx_string_put(ptr->mlx, ptr->win, 870, 160,
					   0x00BBBBFF, "scroll up/down");
		mlx_string_put(ptr->mlx, ptr->win, 870, 480,
					   0x00BBBBFF, "1, 2, 3, 4, 5");
		mlx_string_put(ptr->mlx, ptr->win, 870, 720,
					   0x00BBBBFF, "(only in meme mode):");
		mlx_string_put(ptr->mlx, ptr->win, 870, 740,
					   0x00BBBBFF, "press g");
	}
	if (full->fractal.is_mooving)
		mlx_string_put(ptr->mlx, ptr->win, 870, 220,
					   0x00BBBBFF, "move the cursor");
	else
		mlx_string_put(ptr->mlx, ptr->win, 870, 220,
					   0x00BBBBFF, "torn the moving mode");
}

void	print_menu(t_draw_menu *menu, t_window *ptr, t_full_image *full)
{
	mlx_put_image_to_window(ptr->mlx, ptr->win,
					menu->drawing->image, SIZE_WINDOW_X - SIZE_MENU, 0);
	current_menu(menu, ptr, full);
	mlx_string_put(ptr->mlx, ptr->win, 870, 200,
				   0x00BBBBFF, "rescale fractal:");
	mlx_string_put(ptr->mlx, ptr->win, 870, 520,
				   0x00BBBBFF, "move:");
	mlx_string_put(ptr->mlx, ptr->win, 870, 540,
				   0x00BBBBFF, "     < || >");
	mlx_string_put(ptr->mlx, ptr->win, 870, 540,
				   0x00BBBBFF, "use    ^_");
	mlx_string_put(ptr->mlx, ptr->win, 875, 540,
				   0x00BBBBFF, "     -   - keys");
	mlx_string_put(ptr->mlx, ptr->win, 870, 580,
				   0x00BBBBFF, "set default:");
	mlx_string_put(ptr->mlx, ptr->win, 870, 600,
				   0x00BBBBFF, "space");
	mlx_string_put(ptr->mlx, ptr->win, 870, 640,
				   0x00BBBBFF, "meme mode:");
	mlx_string_put(ptr->mlx, ptr->win, 870, 660,
				   0x00BBBBFF, "press f (on/off)");
	mlx_string_put(ptr->mlx, ptr->win, 870, 680,
				   0x00BBBBFF, "change music");
	write_rest_menu(menu, ptr);
}

void	draw(t_full_image *full)
{
	mlx_clear_window(full->ptr.mlx, full->ptr.win);
	if (full->patrick.on && full->fractal.color_shift == LAST_COLOR && !full->patrick.depr)
		mlx_put_image_to_window(full->ptr.mlx, full->ptr.win,
								full->patrick.stars->image, full->patrick.on * -2, 0);
	else
	{
		draw_fractal(&full->fractal);
//	if (full->fractal.rotate != 0)
//		rotate_all(&(full->z_matrix), full->rotation);
//	img_from_matrix(&full->drawing, full->z_matrix);
		mlx_put_image_to_window(full->ptr.mlx, full->ptr.win,
								full->fractal.drawing->image, 0, 0);
	}
	if (full->menu.on == TRUE)
		print_menu(&full->menu, &full->ptr, full);
}
