/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 01:18:49 by hchau             #+#    #+#             */
/*   Updated: 2020/01/10 01:18:50 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/header.h"

void		image_set_pixel(t_image **image, int x, int y, int color)
{
	int			i;
	t_image		*img;

	i = 0;
	img = *image;
	if (x < 0 || x >= SIZE_WINDOW_X || y < 0 || y >= SIZE_WINDOW_Y)
		return ;
	*(int *)(img->data_addr + ((x * 4 + y * img->size_line))) = color;
}

int			fill_menu(t_image **menu)
{
	int					i;
	int					j;
	unsigned int		mask;

	i = 0;
	j = 0;
	mask = 0xFF000000;
	while (i < SIZE_MENU)
	{
		while (mask > 0xAA000000 && i < SIZE_MENU)
		{
			while (j < SIZE_WINDOW_Y)
			{
				image_set_pixel(menu, i, j++, 0x00CC88FF | mask);
			}
			mask = mask - 0x01000000;
			j = 0;
			i++;
		}
		while (j < SIZE_WINDOW_Y)
			image_set_pixel(menu, i, j++, 0xAACC88FF);
		j = 0;
		i++;
	}
	return (0);
}

void		img_from_matrix(t_image **image, t_coord **z_matrix)
{
	int 	x;
	int 	y;

	x = 0;
	while (x < SIZE_WINDOW_X)
	{
		y = 0;
		while (y < SIZE_WINDOW_Y)
		{
			image_set_pixel(image, z_matrix[x][y].x, z_matrix[x][y].y, z_matrix[x][y].color);
			y++;
		}
		x++;
	}
}

void		clear_image(t_image **image, unsigned long size)
{
	ft_bzero((*image)->data_addr, size);
}

void		create_img(t_image **image, int x, int y, t_window *local)
{
	*image = (t_image *)malloc(sizeof(t_image));
	(*image)->mlx_ptr = local->mlx;
	(*image)->image = mlx_new_image((*image)->mlx_ptr,
											x, y);
	(*image)->data_addr = mlx_get_data_addr((*image)->image,
											&((*image)->bits_per_pixel),
											&((*image)->size_line),
											&((*image)->endian));
	clear_image(&(*image), x * y * 4);
}
