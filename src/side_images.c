//
// Created by Hugor Chau on 2020-01-14.
//

#include "../incs/header.h"

void		open_image(t_image **image, char *filename, int size_x, int size_y)
{
//	(*image) = (t_image *)malloc(sizeof(t_image));
	if (((*image)->image = mlx_xpm_file_to_image((*image)->mlx_ptr,
							filename, &(size_x), &(size_y))) == NULL)
		return;
	((*image))->data_addr = mlx_get_data_addr((*image)->image,
												  &((*image)->bits_per_pixel),
												  &((*image)->size_line),
												  &((*image)->endian));
}