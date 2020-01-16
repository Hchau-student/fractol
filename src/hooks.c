//
// Created by Hugor Chau on 2020-01-11.
//

#include "../incs/header.h"
#include <limits.h>


int		mouse_motion(int x, int y, t_full_image *full)
{
	int 	remember_color;

	if (full->fractal.is_mooving == TRUE)
	{
		full->fractal.count.k.real = 4 * ((double) x / SIZE_WINDOW_X - 0.5);
		full->fractal.count.k.imagine = 4 * ((double) (SIZE_WINDOW_Y - y) / SIZE_WINDOW_Y - 0.5);
	}
	if (full->patrick.on != FAULSE)
	{
		if (full->patrick.on > 50)
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
	draw(full);
	if (full->patrick.on != FAULSE)
	{
		mlx_put_image_to_window(full->ptr.mlx, full->ptr.win,
							full->patrick.drawing->image, x - 20, y - 10);
	}
	if (full->patrick.depr && full->patrick.on > 30)
	{
		mlx_put_image_to_window(full->ptr.mlx, full->ptr.win,
								full->patrick.backgrownd->image, (full->patrick.on - 100) * 3, 200);
	}
	return (0);
}

static double	get_position(double start, double end, double zoom)
{
	return (start + ((end - start) * zoom));
}

int		mouse_scroll(int button, int x, int y, t_full_image *param)
{
	double		zoom;
	double		new_x;
	double		new_y;

	if (button == SCROLL_UP)
		zoom = 1.25;
	else if (button == SCROLL_DOWN)
		zoom = 0.80;
	else
		return (0);
	new_x = (double)x / (SIZE_WINDOW_X / (param->fractal.count.max.real - param->fractal.count.min.real))
			+ param->fractal.count.min.real;
	new_y = (double)y / (SIZE_WINDOW_Y / (param->fractal.count.max.imagine - param->fractal.count.min.imagine))
			* -1 + param->fractal.count.max.imagine;
	param->fractal.count.min.real = get_position(new_x, param->fractal.count.min.real, zoom);
	param->fractal.count.min.imagine = get_position(new_y, param->fractal.count.min.imagine, zoom);
	param->fractal.count.max.real = get_position(new_x, param->fractal.count.max.real, zoom);
	param->fractal.count.max.imagine = get_position(new_y, param->fractal.count.max.imagine, zoom);
	draw(param);
	return (1);
}

int		key_press(int keycode, t_full_image *full)
{
	printf("%d\n", keycode);
	if ((key_menu(keycode, full)) || (set_color_shift(keycode, full))
		|| (key_stop_k_move(keycode, full)) || (key_exit(keycode, full))
		|| (key_default(keycode, full)) || (key_patrick(keycode, full))
		|| (key_map_move(keycode, full)))
		;
	draw(full);
	return (0);
}
