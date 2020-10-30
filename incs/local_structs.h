/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:52:34 by hchau             #+#    #+#             */
/*   Updated: 2020/02/10 14:52:41 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOCAL_STRUCTS_H
# define LOCAL_STRUCTS_H

typedef struct		s_window
{
	void			*mlx;
	void			*win;
	int				x;
	int				y;
}					t_window;

typedef struct		s_image
{
	void			*image;
	char			*data_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	void			*mlx_ptr;
}					t_image;

/*
**		структура комплексного числа
*/
typedef struct		s_complex
{
	long double		x;
	long double		y;
}					t_complex;

/*
**		формула рассчёта изображения фрактала
*/
typedef struct		s_fractal
{
	char			*name;
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
*/
typedef struct		s_draw_fractal
{
	int				start_line;
	int				finish_line;
	int				color_shift;
	int				is_mooving;
	t_image			*drawing;
	t_fractal		count;
}					t_draw_fractal;

/*
**		изображение меню
*/
typedef struct		s_draw_menu
{
	t_image			*drawing;
	int				on;
}					t_draw_menu;

/*
**		изображение мема
*/
typedef struct		s_patrick
{
	int				dr_size;
	int				nxt_dr_size;
	int				stars_size;
	t_image			*drawing;
	t_image			*drawing2;
	t_image			*backgrownd;
	t_image			*stars;
	int				on;
	int				depr;
	int				mouse_x;
	int				mouse_y;
}					t_patrick;
/*
**		слои изображений + окно
*/
typedef struct		s_full_image
{
	t_draw_fractal	fractal;
	t_draw_menu		menu;
	t_patrick		patrick;
	t_window		ptr;
}					t_full_image;

#endif
