/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_motion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:10:50 by hchau             #+#    #+#             */
/*   Updated: 2020/02/10 14:10:56 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/header.h"
#include <limits.h>
#include <stdio.h>

void		key_patrick(int keycode, t_full_image *param)
{
	if (keycode == CHANGE_MUSIC && param->patrick.on != FAULSE)
	{
		param->patrick.depr = param->patrick.depr == TRUE ? FAULSE : TRUE;
		system("pkill afplay");
		if (param->patrick.depr)
			system("afplay ./extra_src/sound-of-silence.mp3 &");
		else
			system("afplay ./extra_src/shooting.mp3 &");
	}
	if (keycode == PAY_RESPECT)
	{
		param->patrick.on = param->patrick.on == FAULSE ? TRUE : FAULSE;
		if (param->patrick.on == FAULSE)
			param->patrick.depr = FAULSE;
		if (param->patrick.on == TRUE)
		{
			system("afplay ./extra_src/shooting.mp3 &");
			system("open \"https://www.youtube.com/watch?v=MSENH3FE2As\"");
		}
		else
		{
			system("pkill afplay");
			system("afplay ./extra_src/wilhelm_scream.mp3 &");
		}
	}
}

void		get_meme_pos(t_full_image *full, int x, int y)
{
	int		remember_color;

	if (full->patrick.on > 60)
	{
		remember_color = full->fractal.color_shift;
		set_defaults(&full->fractal.count, POSITION);
		if (remember_color == LAST_COLOR)
			full->fractal.color_shift = FIRST_COLOR;
		else
			full->fractal.color_shift = --remember_color;
		full->patrick.on = TRUE;
	}
	mouse_scroll(SCROLL_DOWN, x, y, full);
	full->patrick.on++;
}

void		draw_meme_man(t_full_image *full, int x, int y)
{
	if (full->patrick.on == FAULSE)
		return ;
	{
		if (full->patrick.on < 10 ||
			(full->patrick.on > 20 && full->patrick.on < 30)
			|| (full->patrick.on > 40 && full->patrick.on < 50))
			mlx_put_image_to_window(full->ptr.mlx, full->ptr.win,
							full->patrick.drawing->image, x - 20, y - 10);
		else
			mlx_put_image_to_window(full->ptr.mlx, full->ptr.win,
							full->patrick.drawing2->image, x - 20, y - 10);
	}
	if (full->patrick.depr && full->patrick.on > 30)
	{
		mlx_put_image_to_window(full->ptr.mlx, full->ptr.win,
								full->patrick.backgrownd->image,
								(full->patrick.on - 100) * 3, 200);
	}
}

int			mouse_motion(int x, int y, t_full_image *full)
{
	if (full->fractal.is_mooving == TRUE)
	{
		full->fractal.count.k.x = 4 * ((double)x / SIZE_WINDOW_X - 0.5);
		full->fractal.count.k.y =
				4 * ((double)(SIZE_WINDOW_Y - y) / SIZE_WINDOW_Y - 0.5);
	}
	full->patrick.mouse_x = x;
	full->patrick.mouse_y = y;
	draw(full);
	if (full->patrick.on != FAULSE)
		get_meme_pos(full, x, y);
	draw_meme_man(full, x, y);
	return (0);
}
