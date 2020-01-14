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

void		put_mask(t_image **image, int mask, int x, int y)
{

	int					i;
	int					j;

	i = 0;
	j = 0;
	while (i < x)
	{
		while (j < y)
		{
			*(int *)((*image)->data_addr + ((i * 4 + j * (*image)->size_line))) += mask;
			j++;
		}
		j = 0;
		i++;
	}
}

//*(int *)(img->data_addr + ((x * 4 + y * img->size_line))) = color;