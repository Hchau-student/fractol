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

int		key_rotate(int keycode, t_full_image *param)
{
	if (keycode == 12)
		param->rotation.z_rot -= 5.0;
	else if (keycode == 14)
		param->rotation.z_rot += 5.0;
	else if (keycode == 1)
		param->rotation.x_rot -= 5.0;
	else if (keycode == 13)
		param->rotation.x_rot += 5.0;
	else if (keycode == 0)
		param->rotation.y_rot -= 5.0;
	else if (keycode == 2)
		param->rotation.y_rot += 5.0;
	else
		return (0);
	param->fractal.rotate = 1;
	return (1);
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

static double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

int		mouse_scroll(int button, int x, int y, t_full_image *param)
{
	double		zoom;
	double		interpolation;
	double		new_x;
	double		new_y;

	if (button == SCROLL_UP)
		zoom = 0.80;
	else if (button == SCROLL_DOWN)
		zoom = 1.20;
	else
		return (0);
	new_x = (double)x / (SIZE_WINDOW_X / (param->fractal.max.real - param->fractal.min.real))
			+ param->fractal.min.real;
	new_y = (double)y / (SIZE_WINDOW_Y / (param->fractal.max.imagine - param->fractal.min.imagine))
			* -1 + param->fractal.max.imagine;
	interpolation = 1.0 / zoom;
	param->fractal.min.real = interpolate(new_x, param->fractal.min.real, interpolation);
	param->fractal.min.imagine = interpolate(new_y, param->fractal.min.imagine, interpolation);
	param->fractal.max.real = interpolate(new_x, param->fractal.max.real, interpolation);
	param->fractal.max.imagine = interpolate(new_y, param->fractal.max.imagine, interpolation);
	draw(param);
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
//	printf("%d\n", keycode);
	if ((key_menu(keycode, full)) || (set_color_shift(keycode, full))
		|| (key_exit(keycode, full)))
		;
	draw(full);
	return (0);
}
