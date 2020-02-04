//
// Created by Hugor Chau on 2020-01-14.
//

#include "../incs/header.h"

/*
**		отрисовка пикселя мандельброт
*/
int		mandelbrot(t_fractal *mandelbrot)
{
	int				iteration;
	t_complex		z;
	long double		extra;
	t_complex		local;

	iteration = 0;
	z.x = mandelbrot->constant.x;
	z.y = mandelbrot->constant.y;
	local.x = powl(z.x, 2.0);
	local.y = powl(z.y, 2.0);
	while ((local.x + local.y) <= 4
		   && iteration < mandelbrot->max_iteration)
	{
		extra = z.x;
		z.x = local.x + mandelbrot->constant.x - (mandelbrot->k.y + local.y);
		z.y = 2.0 * extra * z.y + mandelbrot->constant.y - mandelbrot->k.x;
		local.x = powl(z.x, 2.0);
		local.y = powl(z.y, 2.0);
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
	z.x = julia->constant.x;
	z.y = julia->constant.y;
	while (pow(z.x, 2.0) + pow(z.y, 2.0) <= 4
		   && iteration < julia->max_iteration)
	{
		extra = z.x;
		z.x = pow(z.x, 2.0) - pow(z.y, 2.0) + julia->k.x;
		z.y = 2.0 * extra * z.y + julia->k.y;
		iteration++;
	}
	return (iteration);
}
