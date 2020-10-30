/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:53:04 by hchau             #+#    #+#             */
/*   Updated: 2020/02/10 13:53:11 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/header.h"
#include <sys/types.h>
#include <unistd.h>

int		key_default(int keycode, t_full_image *param)
{
	if (keycode == DEFAULT)
	{
		set_defaults(&param->fractal.count, ALL);
	}
	else
		return (0);
	return (1);
}

int		key_menu(int keycode, t_full_image *param)
{
	if (keycode == MENU)
	{
		param->menu.on = param->menu.on == TRUE ? FAULSE : TRUE;
		return (1);
	}
	return (0);
}

int		key_stop_k_move(int keycode, t_full_image *param)
{
	if (keycode == MOOVE)
		param->fractal.is_mooving =
				param->fractal.is_mooving == FAULSE ? TRUE : FAULSE;
	else
		return (0);
	return (1);
}

void	move(double shift, long double *res1, long double *res2)
{
	*res1 += shift / 100.0;
	*res2 += shift / 100.0;
}

int		key_map_move(int keycode, t_full_image *param)
{
	double		shift;

	shift = param->fractal.count.max.x - param->fractal.count.min.x;
	if (keycode == RIGHT)
		move(shift, &param->fractal.count.max.x, &param->fractal.count.min.x);
	else if (keycode == LEFT)
	{
		shift *= -1;
		move(shift, &param->fractal.count.max.x, &param->fractal.count.min.x);
	}
	else if (keycode == DOWN)
	{
		shift = param->fractal.count.max.y - param->fractal.count.min.y;
		move(shift, &param->fractal.count.max.y, &param->fractal.count.min.y);
	}
	else if (keycode == UP)
	{
		shift = (param->fractal.count.max.y - param->fractal.count.min.y) * -1;
		move(shift, &param->fractal.count.max.y, &param->fractal.count.min.y);
	}
	else
		return (0);
	return (1);
}
