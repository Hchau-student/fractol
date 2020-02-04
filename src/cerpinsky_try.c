//
// Created by Hugor Chau on 2020-01-17.
//

/*
**		отрисовка пикселя
*/
//
//int			fuck(t_fractal *cock)
//{
//	return (0);
//}

#include "../incs/header.h"

t_coord		**z_buf()
{

}

int			fuck(t_fractal *cock)
{
	int			iteration;
	t_complex	z;
	double		newx;
	double		newy;
	double		newz;
	double th;
	double ph;
	double		z_rot;
	double pi = 3.14159265;
	double r;
	double yang;
	double zang;

	iteration = 0;
	z.x = cock->constant.x;
	z.y = cock->constant.y;
	z_rot = z.x * z.y + cock->constant.x;
	r = sqrt(pow(z.x, 3.0) + pow(z.y, 3.0) + pow(z_rot, 3.0));
	th =  atan2(z.x, z.y) * 3.0;
	ph = asin(z_rot/r) *  3.0;
	r = pow(r, 3.0);

//	yang = atan2(sqrt(pow(z.x, 8.0) + pow(z.y, 8.0)) , z_rot);
//	zang = atan2(z.y , z.x);

//	x  := r * cos(ph) * cos(th);
//	y  := r * cos(ph) * sin(th);
//	z  := r * sin(ph);
//
//	x := x + Сx;
//	y := y + Сy;
//	z := z + Сz;


	while (pow(z.x, 3.0) + pow(z.y, 3.0) + pow(z_rot, 3.0) <=  4.0 && iteration < cock->max_iteration)
	{
		z.x = (r) * cos(ph) * cos(th);
		z.y = r * cos(ph) * sin(th);
		z_rot = r * sin(ph);
		z.x = z.x + cock->constant.x;
		z.y += cock->constant.y;
		z_rot += 2.0;
		iteration++;
	}
	return (iteration);
}
