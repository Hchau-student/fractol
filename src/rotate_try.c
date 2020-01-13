//
// Created by Hugor Chau on 2020-01-13.
//

#include "../incs/header.h"

void	prepare_cur_point(double *x, double *y, double *z, t_coord coord)
{
	*x = (double)coord.x;
	*y = (double)coord.y;
	*z = (double)coord.z;
}

void	rotate_node(t_coord *current, t_rotation rot)
{
	double		x;
	double		y;
	double		z;

	prepare_cur_point(&x, &y, &z, *current);
	current->y = y * cos(rot.x_rot) + z * sin(rot.x_rot);
	current->z = z * cos(rot.x_rot) - y * sin(rot.x_rot);
	prepare_cur_point(&x, &y, &z, *current);
	current->x = x * cos(rot.z_rot) - y * sin(rot.z_rot);
	current->y = x * sin(rot.z_rot) + y * cos(rot.z_rot);
	prepare_cur_point(&x, &y, &z, *current);
	current->x = x * cos(rot.y_rot) + z * sin(rot.y_rot);
	current->z = z * cos(rot.y_rot) - x * sin(rot.y_rot);
}

void	rotate_all(t_coord ***z_matrix, t_rotation rot)
{
	int 	x;
	int 	y;

	x = 0;
	while (x < SIZE_WINDOW_X)
	{
		y = 0;
		while (y < SIZE_WINDOW_Y)
		{
			rotate_node(&(*z_matrix)[x][y], rot);
			y++;
		}
		x++;
	}
}
