//
// Created by Hugor Chau on 2020-01-11.
//

#include "../incs/header.h"

int		close_fractol(t_window *param)
{
	exit(0);
	return (0);
}

int		key_menu(int keycode, t_full_image *param)
{
	if (keycode == MENU)
	{
		param->menu_on = param->menu_on == TRUE ? FAULSE : TRUE;
		draw(param);
		return (1);
	}
	return (0);
}

int		mouse_scroll(int button, int x, int y, t_full_image *param)
{
	x = 0;
	y = 0;
	if (button == SCROLL_UP)
	{
		ft_putstr("up\n");
	}
	if (button == SCROLL_DOWN)
	{
		ft_putstr("down\n");
	}
	return (0);
}

int		key_exit(int keycode, t_full_image *full_image)
{
	if (keycode == ESCAPE)
	{
		exit(0);
	}
	return (0);
}

int		key_press(int keycode, t_full_image *full)
{
	printf("%d", keycode);
	if ((key_menu(keycode, full)) || (key_exit(keycode, full)))
		;
	draw(full);
	return (0);
}
