//
// Created by Hugor Chau on 2020-01-13.
//
#include "../incs/header.h"
/*
**		отрисовка пикселя мандельброт
*/
int		mandelbrot(t_fractal *mandelbrot)
{
	int			iteration;
	t_complex	z;
	double		extra;
	t_complex	local;

	iteration = 0;
	z.real = mandelbrot->constant.real;
	z.imagine = mandelbrot->constant.imagine;
	local.real = pow(z.real, 2.0);
	local.imagine = pow(z.imagine, 2.0);
	while ((local.real + local.imagine) <= 4
		   && iteration < mandelbrot->max_iteration)
	{
		extra = z.real;
		z.real = local.real - local.imagine + mandelbrot->constant.real;
		z.imagine = 2.0 * extra * z.imagine + mandelbrot->constant.imagine;
		local.real = pow(z.real, 2.0);
		local.imagine = pow(z.imagine, 2.0);
		iteration++;
	}
	return (iteration);
}

/*
**		отрисовка пикселя Жулиа
*/
int			julia(t_fractal *julia)
{
	int			iteration;
	t_complex	z;
	double		extra;
	t_complex	local;

	iteration = 0;
	z.real = julia->constant.real;
	z.imagine = julia->constant.imagine;
	while (pow(z.real, 2.0) + pow(z.imagine, 2.0) <= 4
		   && iteration < julia->max_iteration)
	{
		extra = z.real;
		z.real = pow(z.real, 2.0) - pow(z.imagine, 2.0) + julia->k.real;
		z.imagine = 2.0 * extra * z.imagine + julia->k.imagine;
		iteration++;
	}
	return (iteration);
}
/*
**		рассчёт цвета и только
*/
int		get_color(int iteration, int max_iteration, int shift)
{
	double	t;
	int 	red;
	int 	green;
	int		blue;

	t = (double)iteration / (double)max_iteration;
	if (iteration == 50)
		return (0x00);
	if (shift == 0)
	{
		red = (int)(9 * (1 - t) * pow(t, 3) * 255);
		green = (int)(8.5 * pow((1 - t), 3) * t * 255) & 0x10;
		blue =  (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	}
	else if (shift == -1)
	{
		red = (int) (15 * pow((1 - t), 2) * pow(t, 2) * 255);
		green = (int) (9 * (1 - t) * pow(t, 3) * 255);
		blue =   (int) (8.5 * pow((1 - t), 3) * t * 255);
	}
	else if (shift == -2)
	{
		red = (int)(8.5 * pow((1 - t), 3) * t * 255);
		green =  (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
		blue = (int)(9 * (1 - t) * pow(t, 3) * 255);
	}
	else if (shift == -3)
	{
		red = ((int)(8.5 * pow((1 - t), 3) * t * 255) & 0x11) * 100;
		green = ((int)(15 * pow((1 - t), 2) * pow(t, 2) * 255) & 0x11) * 100;
		blue = ((int)(9 * (1 - t) * pow(t, 3) * 255) & 0x11) * 100;
	}
	else if (shift == -4)
	{
		red = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
		green =  (int)(8.5 * pow((1 - t), 3) * t * 255);
		blue = (int)(9 * (1 - t) * pow(t, 3) * 255);
	}
	return (red << 16 | green << 8 | blue);
}
/*
**		разбиение на потоки, передача пикселей в следующую функцию
*/
int		get_fractal_img(t_full_image *full)
{
	int 			y;
	int 			x;
	int				i;

	y = full->fractal.start_line;
	i = 0;
	full->fractal.cur.real = (full->fractal.max.real - full->fractal.min.real)
			/ (SIZE_WINDOW_X - 1);
	full->fractal.cur.imagine = (full->fractal.max.imagine - full->fractal.min.imagine)
			/ (SIZE_WINDOW_Y - 1);
	while (y < full->fractal.finish_line && y < SIZE_WINDOW_Y)
	{
		full->fractal.constant.imagine = full->fractal.max.imagine - y * full->fractal.cur.imagine;
		x = 0;
		while (x < SIZE_WINDOW_X)
		{
			full->fractal.constant.real = full->fractal.min.real + x * full->fractal.cur.real;
			image_set_pixel(&full->drawing, x, y,
					get_color(full->fractal.count_fractal(&full->fractal),
							full->fractal.max_iteration, full->fractal.color_shift));
			x++;
		}
		y++;
	}
	return (0);
}

/*
**		скорость, подруга!
*/
void		draw_fractal(t_full_image *full)
{
	pthread_t		threads[THREADS];
	t_full_image	current[THREADS];
	int				i;

	full->fractal.cur.real = (full->fractal.max.real - full->fractal.min.real)
			/ (SIZE_WINDOW_X - 1);
	full->fractal.cur.imagine = (full->fractal.max.imagine - full->fractal.min.imagine)
			/ (SIZE_WINDOW_Y - 1);
	i = 0;
	while (i < THREADS)
	{
		current[i] = *full;
		current[i].fractal.start_line = i * (SIZE_WINDOW_Y / THREADS);
		current[i].fractal.finish_line = (i + 1) * (SIZE_WINDOW_Y / THREADS);
		pthread_create(&threads[i], NULL,
						   (void *(*)(void *))get_fractal_img, (void *)&current[i]);
		i++;
	}
	while (i-- > 0)
		pthread_join(threads[i], NULL);
}