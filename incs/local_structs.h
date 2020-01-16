//
// Created by Hugor Chau on 2020-01-15.
//

#ifndef LOCAL_STRUCTS_H
#define LOCAL_STRUCTS_H
#include "graphic_structs.h"

/*
**		все, что необходимо для вычисления фрактала
*/

typedef union		s_union
{
	long double		original;
	short int		set[9];
}					t_union;

typedef struct		s_fractal
{
	char 			*name;
	int				max_iteration;
	t_complex		k;
	t_complex		min;
	t_complex		max;
	t_complex		constant;
	t_complex		cur;
	int				(*formula)(struct s_fractal *);
}					t_fractal;

/*
**		изображение фрактала
**		int			start_line;
**		int			finish_line;
**		для реализации мультипоточности для более быстрой обработки
*/
typedef struct		s_draw_fractal
{
	int				start_line;
	int				finish_line;
	int				rotate;			//флаг вращения
	int				color_shift;
	t_rotation		rotation;		//оси вращения
	t_coord			**z_matrix;		//z-буффер
	int				is_mooving;		//флаг расчёта коэффициента искажения фрактала
	t_image			*drawing;		//само изображение
	t_fractal		count;		//фотмулы фрактала
	t_coord			move_map;

}					t_draw_fractal;

typedef struct		s_draw_menu
{
	t_image			*drawing;
	int				on;
}					t_draw_menu;

typedef struct		s_patrick
{
	t_image			*drawing;
	t_image			*backgrownd;
	t_image			*stars;
	int				on;
	int				depr;
}					t_patrick;

typedef struct		s_full_image
{
	/*
	**		все изображения
	*/
	t_draw_fractal	fractal;
	t_draw_menu		menu;
	t_patrick		patrick;
	/*
	**		передаваемые значения
	*/
	t_window		ptr;
}					t_full_image;

#endif
