/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_formulas.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 11:52:43 by hchau             #+#    #+#             */
/*   Updated: 2020/02/10 11:52:47 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		julia(t_fractal *julia)
{
	int			iteration;
	t_complex	z;
	double		extra;

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

/*
**		отрисовка пикселя Burning Ship
*/

int		fuck(t_fractal *cock)
{
	t_complex	z;
	int			iteration;
	double		extra;

	iteration = 0;
	z.x = cock->constant.x + cock->k.y - cock->k.x;
	z.y = cock->constant.y + cock->k.y;
	while (z.x * z.x + z.y * z.y < 4 && iteration < cock->max_iteration)
	{
		extra = z.x * z.x - z.y * z.y + cock->constant.x;
		z.y = -2.0 * fabsl(z.x * z.y) + cock->constant.y + cock->k.y;
		z.y = z.y < 0.0 ? z.y * -1 : z.y;
		z.x = extra + cock->k.x < 0.0 ? (extra + cock->k.x) * -1 :
				extra + cock->k.x;
		iteration++;
	}
	return (iteration);
}
