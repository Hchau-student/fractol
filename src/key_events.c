//
// Created by Hugor Chau on 2020-01-15.
//

#include "../incs/header.h"

int		key_patrick(int keycode, t_full_image *param)
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
			system("afplay ./extra_src/shooting.mp3 &");
		else
		{
			system("pkill afplay");
			system("afplay ./extra_src/wilhelm_scream.mp3 &");
		}
	}
	else
		return (0);
	return (1);
}

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
		param->fractal.is_mooving = param->fractal.is_mooving == FAULSE ? TRUE : FAULSE;
	else
		return (0);
	return (1);
}

static double	get_position(double start, double end, double zoom)
{
	return (start + ((end - start) * zoom));
}

int		key_map_move(int keycode, t_full_image *param)
{
	double		shift;

	if (keycode == LEFT)
	{
		shift = param->fractal.count.max.real - param->fractal.count.min.real;
		param->fractal.count.max.real += shift / 100.0;
		param->fractal.count.min.real += shift / 100.0;
	}
	else if (keycode == RIGHT)
	{
		shift = param->fractal.count.max.real - param->fractal.count.min.real;
		param->fractal.count.max.real -= shift / 100.0;
		param->fractal.count.min.real -= shift / 100.0;
	}
	else if (keycode == DOWN)
	{
		shift = param->fractal.count.max.imagine - param->fractal.count.min.imagine;
		param->fractal.count.max.imagine += shift / 100.0;
		param->fractal.count.min.imagine += shift / 100.0;
	}
	else if (keycode == UP)
	{
		shift = param->fractal.count.max.imagine - param->fractal.count.min.imagine;
		param->fractal.count.max.imagine -= shift / 100.0;
		param->fractal.count.min.imagine -= shift / 100.0;
	}
}

//
//int		key_rotate(int keycode, t_full_image *param)
//{
//	if (keycode == 12)
//		param->fractal.rotation.z_rot -= 5.0;
//	else if (keycode == 14)
//		param->fractal.rotation.z_rot += 5.0;
//	else if (keycode == 1)
//		param->fractal.rotation.x_rot -= 5.0;
//	else if (keycode == 13)
//		param->fractal.rotation.x_rot += 5.0;
//	else if (keycode == 0)
//		param->fractal.rotation.y_rot -= 5.0;
//	else if (keycode == 2)
//		param->fractal.rotation.y_rot += 5.0;
//	else
//		return (0);
//	param->fractal.rotate = 1;
//	return (1);
//}

int		key_exit(int keycode, t_full_image *param)
{
	if (keycode == ESCAPE)
	{
		if (param->patrick.on != FAULSE)
			system("pkill afplay");
		exit(0);
	}
	return (0);
}
