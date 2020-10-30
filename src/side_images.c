/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:51:21 by hchau             #+#    #+#             */
/*   Updated: 2020/02/10 13:51:28 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/header.h"

int			open_image(t_image **image, char *filename, int size_x, int size_y)
{
	if (((*image)->image = mlx_xpm_file_to_image((*image)->mlx_ptr,
							filename, &(size_x), &(size_y))) == NULL)
		return (0);
	((*image))->data_addr = mlx_get_data_addr((*image)->image,
												&((*image)->bits_per_pixel),
												&((*image)->size_line),
												&((*image)->endian));
	return (size_x * size_y * 4);
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
			*(int *)((*image)->data_addr +
			((i * 4 + j * (*image)->size_line))) += mask;
			j++;
		}
		j = 0;
		i++;
	}
}
