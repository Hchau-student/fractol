//
// Created by Hugor Chau on 2020-01-15.
//

#include "../incs/header.h"

int		set_color_shift(int keycode, t_full_image *param)
{
	if (DARK_THEME)
		param->fractal.color_shift = 0;
	else if (BLUE_THEME)
		param->fractal.color_shift = -1;
	else if (RED_THEME)
		param->fractal.color_shift = -2;
	else if (CLOWN_THEME)
		param->fractal.color_shift = -3;
	else if (GREEN_THEME)
		param->fractal.color_shift = -4;
	else
		return (0);
	return (1);
}

int		close_fractol(t_window *param)
{
	exit(0);
	return (0);
}

void	set_defaults(t_fractal *fractal, int flag)
{
	fractal->max_iteration = 50;
	fractal->min.real = -2.0;
	fractal->min.imagine = -2.0;
	fractal->max.real = 2.0;
	fractal->max.imagine = 2.0;
	fractal->cur.real = 0.0;
	if (flag != ALL)
		return ;
	if (ft_strequ(fractal->name, "Julia") == TRUE)
	{
		fractal->k.real = 0.4;
		fractal->k.imagine = 0.1;
	}
	else
	{
		fractal->k.real = 0.0;
		fractal->k.imagine = 0.0;
	}
}
