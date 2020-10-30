/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_full.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:44:56 by hchau             #+#    #+#             */
/*   Updated: 2020/02/10 13:45:03 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/header.h"

void	prepare_fractal(t_draw_fractal *full, t_fractal *fractal, t_window *ptr)
{
	full->is_mooving = TRUE;
	full->count = *fractal;
	create_img(&full->drawing, SIZE_WINDOW_X, SIZE_WINDOW_Y, ptr);
}

void	prepare_menu(t_draw_menu *menu, t_window *ptr)
{
	create_img(&menu->drawing, SIZE_MENU, SIZE_WINDOW_Y, ptr);
	menu->on = TRUE;
	fill_menu(&menu->drawing);
}

void	prepare_patrick_mode(t_patrick *full, t_window *ptr)
{
	full->backgrownd = (t_image *)malloc(sizeof(t_image));
	full->drawing = (t_image *)malloc(sizeof(t_image));
	full->drawing2 = (t_image *)malloc(sizeof(t_image));
	full->stars = (t_image *)malloc(sizeof(t_image));
	full->drawing->mlx_ptr = ptr->mlx;
	full->drawing2->mlx_ptr = ptr->mlx;
	full->backgrownd->mlx_ptr = ptr->mlx;
	full->stars->mlx_ptr = ptr->mlx;
	full->on = FAULSE;
	full->depr = FAULSE;
	full->dr_size = open_image(&full->drawing,
			"./extra_src/1.xpm", SIZE_WINDOW_X, SIZE_WINDOW_Y);
	full->nxt_dr_size = open_image(&full->drawing2,
			"./extra_src/2.xpm", SIZE_WINDOW_X, SIZE_WINDOW_Y);
	open_image(&full->backgrownd,
			"./extra_src/trees.xpm", SIZE_WINDOW_X, SIZE_WINDOW_Y);
	full->stars_size = open_image(&full->stars,
			"./extra_src/cosm.xpm", SIZE_WINDOW_X, SIZE_WINDOW_Y);
	put_mask(&full->backgrownd, 0xEC000000, 1400, 926);
}

void	init_full(t_full_image *full, t_window ptr, t_fractal *fractal)
{
	ft_bzero(full, sizeof(t_full_image));
	full->ptr = ptr;
	prepare_fractal(&full->fractal, fractal, &ptr);
	prepare_menu(&full->menu, &ptr);
	prepare_patrick_mode(&full->patrick, &ptr);
}
