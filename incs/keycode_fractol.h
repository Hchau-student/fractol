
#ifndef KEYCODE_FRACTOL_H
# define KEYCODE_FRACTOL_H
# define ESCAPE				53
# define MENU				4
/*
**		mouse
*/
# define SCROLL_UP			5
# define SCROLL_DOWN		4
/*
**		move image
*/
# define UP					126
# define DOWN				125
# define LEFT				123
# define RIGHT				124
/*
**		colors in code
*/
# define DARK				0
# define BLUE				-1
# define RED				-2
# define CLOWN				-3
# define GREEN				-4
# define LAST_COLOR			-4
# define FIRST_COLOR		0
/*
**		colors in keycode
*/
# define DARK_THEME			keycode == 18 || keycode == 83
# define BLUE_THEME			keycode == 19 || keycode == 84
# define RED_THEME			keycode == 20 || keycode == 85
# define CLOWN_THEME		keycode == 21 || keycode == 86
# define GREEN_THEME		keycode == 23 || keycode == 87
/*
**		fix/default
*/
# define MOOVE				36
# define DEFAULT			49
/*
**		Patrick mode
*/
# define PAY_RESPECT		3
# define CHANGE_MUSIC		5
#endif
