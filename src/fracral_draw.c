//
// Created by Hugor Chau on 2020-01-13.
//
#include "../incs/header.h"

/*
**		рассчёт цвета и только
*/

void	recalculate(int *first, int *second, int *third, double t)
{
	*first = (int)(9 * (1 - t) * pow(t, 3) * 255);
	*second = (int)(8.5 * pow((1 - t), 3) * t * 255);
	*third = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
}

int		get_color(int iteration, int max_iteration, int shift)
{
	double	t;
	int 	red;
	int 	green;
	int		blue;

	t = (double)iteration / (double)max_iteration;
	if (shift == DARK)
	{
		recalculate(&red, &green, &blue, t);
		green = green & 0x15;
	}
	else if (shift == BLUE)
		recalculate(&green, &blue, &red, t);
	else if (shift == RED)
		recalculate(&blue, &red, &green, t);
	else if (shift == CLOWN)
	{
		recalculate(&blue, &red, &green, t);
		red = (red & 0x11) * 100;
		green = (green & 0x11) * 100;
		blue = (blue & 0x11) * 100;
	}
	else if (shift == GREEN)
		recalculate(&blue, &green, &red, t);
	return (red << 16 | green << 8 | blue);
}

/*
**		разбиение на потоки, передача пикселей в следующую функцию
*/

int		get_fractal_img(t_draw_fractal *full)
{
	int 			y;
	int 			x;
	int				i;

	y = full->start_line;
	i = 0;
	while (y < full->finish_line && y < SIZE_WINDOW_Y)
	{
		full->count.constant.y = full->count.max.y - y * full->count.cur.y;
		x = 0;
		while (x < SIZE_WINDOW_X)
		{
			full->count.constant.x = full->count.min.x + x * full->count.cur.x;
			image_set_pixel(&full->drawing, x, y,
					get_color(full->count.formula(&full->count),
							full->count.max_iteration, full->color_shift));
			x++;
		}
		y++;
	}
	return (0);
}

void		draw_fractal(t_draw_fractal *fractal)
{
	pthread_t		threads[THREADS];
	t_draw_fractal	current[THREADS];
	int				i;

	fractal->count.cur.x = (fractal->count.max.x - fractal->count.min.x)
							  / (SIZE_WINDOW_X - 1);
	fractal->count.cur.y = (fractal->count.max.y - fractal->count.min.y)
								 / (SIZE_WINDOW_Y - 1);
	i = 0;
	while (i < THREADS)
	{
		current[i] = *fractal;
		current[i].start_line = i * (SIZE_WINDOW_Y / THREADS);
		current[i].finish_line = (i + 1) * (SIZE_WINDOW_Y / THREADS);
		pthread_create(&threads[i], NULL,
					   (void *(*)(void *))get_fractal_img, (void *)&current[i]);
		i++;
	}
	while (i-- > 0)
		pthread_join(threads[i], NULL);
}
