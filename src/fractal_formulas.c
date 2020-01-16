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
	z.real = mandelbrot->constant.real;
	z.imagine = mandelbrot->constant.imagine;
	local.real = powl(z.real, 2.0);
	local.imagine = powl(z.imagine, 2.0);
	while ((local.real + local.imagine) <= 4
		   && iteration < mandelbrot->max_iteration)
	{
		extra = z.real;
		z.real = local.real + mandelbrot->constant.real - (mandelbrot->k.real + local.imagine);
		z.imagine = 2.0 * extra * z.imagine + mandelbrot->constant.imagine - mandelbrot->k.real;
		local.real = powl(z.real, 2.0);
		local.imagine = powl(z.imagine, 2.0);
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
**		отрисовка пикселя ХУЙ БЛЯТЬ
*/

int			fuck(t_fractal *cock)
{
	return (0);
}
