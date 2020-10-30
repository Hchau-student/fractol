/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 11:40:58 by hchau             #+#    #+#             */
/*   Updated: 2020/02/10 11:40:59 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/header.h"

int		set_color_shift(int keycode, t_full_image *param)
{
	if (keycode == DARK_THEME || keycode == DARK_THEME_O)
		param->fractal.color_shift = 0;
	else if (keycode == BLUE_THEME || keycode == BLUE_THEME_O)
		param->fractal.color_shift = -1;
	else if (keycode == RED_THEME || keycode == RED_THEME_O)
		param->fractal.color_shift = -2;
	else if (keycode == CLOWN_THEME || keycode == CLOWN_THEME_O)
		param->fractal.color_shift = -3;
	else if (keycode == GREEN_THEME || keycode == GREEN_THEME_O)
		param->fractal.color_shift = -4;
	else
		return (0);
	return (1);
}

void	set_defaults(t_fractal *fractal, int flag)
{
	fractal->max_iteration = 50;
	fractal->min.x = -2.0;
	fractal->min.y = -2.0;
	fractal->max.x = 2.0;
	fractal->max.y = 2.0;
	fractal->cur.x = 0.0;
	if (flag != ALL)
		return ;
	if (ft_strequ(fractal->name, "Julia") == TRUE)
	{
		fractal->k.x = 0.4;
		fractal->k.y = 0.1;
	}
	else
	{
		fractal->k.x = 0.0;
		fractal->k.y = 0.0;
	}
}
