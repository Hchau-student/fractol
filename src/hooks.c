//
// Created by Hugor Chau on 2020-01-11.
//

#include "../incs/header.h"

int		close_fractol(t_window *param)
{
	exit(0);
	return (0);
}

int		key_menu(int keycode, t_full_image *param)
{
	if (keycode == MENU)
	{
		param->menu_on = param->menu_on == TRUE ? FAULSE : TRUE;
		return (1);
	}
	return (0);
}

int		set_color_shift(int keycode, t_full_image *param)
{
	if (keycode == 18 || keycode == 83)
		param->fractal.color_shift = 0;
	else if (keycode == 19 || keycode == 84)
		param->fractal.color_shift = -1;
	else if (keycode == 20 || keycode == 85)
		param->fractal.color_shift = -2;
	else if (keycode == 21 || keycode == 86)
		param->fractal.color_shift = -3;
	else if (keycode == 23 || keycode == 87)
		param->fractal.color_shift = -4;
	else
		return (0);
	return (1);
}

int		mouse_scroll(int button, int x, int y, t_full_image *param)
{
	x = 0;
	y = 0;
	if (button == SCROLL_UP)
	{
		clear_image(&param->drawing, SIZE_WINDOW_Y * SIZE_WINDOW_X);
		param->fractal.max.real += 0.2;
		param->fractal.max.imagine += 0.2;
		draw(param);
	}
	else if (button == SCROLL_DOWN)
	{
		clear_image(&param->drawing, SIZE_WINDOW_Y * SIZE_WINDOW_X);
		param->fractal.max.real -= 0.2;
		param->fractal.max.imagine -= 0.2;
		draw(param);
	}
	else
		return (0);
	return (1);
}

int		key_exit(int keycode, t_full_image *full_image)
{
	if (keycode == ESCAPE)
	{
		exit(0);
	}
	return (0);
}

int		key_press(int keycode, t_full_image *full)
{
	printf("%d\n", keycode);
	if ((key_menu(keycode, full)) || (set_color_shift(keycode, full))
		|| (key_exit(keycode, full)))
		;
	draw(full);
	return (0);
}
