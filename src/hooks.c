/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 11:51:19 by hchau             #+#    #+#             */
/*   Updated: 2020/02/10 11:51:23 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/header.h"
#include <limits.h>
#include <stdio.h>

static double	get_position(double start, double end, int button)
{
	if (button == SCROLL_UP)
		return (start + ((end - start) * ZOOM_IN));
	return (start + ((end - start) * ZOOM_OUT));
}

int				mouse_scroll(int button, int x, int y, t_full_image *param)
{
	double		new_x;
	double		new_y;

	if (button != SCROLL_UP && button != SCROLL_DOWN)
		return (0);
	new_x = (double)x / (SIZE_WINDOW_X /
			(param->fractal.count.max.x - param->fractal.count.min.x))
			+ param->fractal.count.min.x;
	new_y = (double)y / (SIZE_WINDOW_Y /
			(param->fractal.count.max.y - param->fractal.count.min.y))
			* -1 + param->fractal.count.max.y;
	param->fractal.count.min.x = get_position(new_x,
			param->fractal.count.min.x, button);
	param->fractal.count.min.y = get_position(new_y,
			param->fractal.count.min.y, button);
	param->fractal.count.max.x = get_position(new_x,
			param->fractal.count.max.x, button);
	param->fractal.count.max.y = get_position(new_y,
			param->fractal.count.max.y, button);
	draw(param);
	return (1);
}

int				key_press(int keycode, t_full_image *full)
{
	if ((key_menu(keycode, full)) || (set_color_shift(keycode, full))
		|| (key_stop_k_move(keycode, full)) || (key_exit(keycode, full))
		|| (key_default(keycode, full))
		|| (key_map_move(keycode, full)))
		;
	key_patrick(keycode, full);
//	draw(full);
	if (full->patrick.on != FAULSE)
		get_meme_pos(full, full->patrick.mouse_x, full->patrick.mouse_y);
	draw(full);
	draw_meme_man(full, full->patrick.mouse_x, full->patrick.mouse_y);
	return (0);
}
