/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 10:11:37 by hchau             #+#    #+#             */
/*   Updated: 2019/12/28 10:11:39 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include "fractol_err.h"
# include "keycode_fractol.h"
# include "local_structs.h"
# include "../libft/libft.h"
# include "mlx.h"
# include <math.h>
# include <pthread.h>
# define SIZE_MENU		350
# define SIZE_WINDOW_X	1000
# define SIZE_WINDOW_Y	1000
# define TRUE			1
# define FAULSE			0
# define HELP			-1
# define FRACTAL_NUM	4
# define THREADS		10
# define ALL			1
# define POSITION		0
# define ZOOM_IN		1.25
# define ZOOM_OUT		0.80

/*
**		programm core
*/
void		start_the_programm(t_fractal *fractal);
void		init_full(t_full_image *full, t_window ptr, t_fractal *fractal);
/*
**		events
*/
void		manage_processes(t_full_image *full);
int			key_press(int keycode, t_full_image *param);
int			close_fractol(t_full_image *param);
int			mouse_scroll(int button, int x, int y, t_full_image *param);
int			mouse_motion(int x, int y, t_full_image *full);
int			key_stop_k_move(int keycode, t_full_image *param);
/*
**		key press
*/
void		key_patrick(int keycode, t_full_image *param);
int			key_default(int keycode, t_full_image *param);
int			key_menu(int keycode, t_full_image *param);
int			key_stop_k_move(int keycode, t_full_image *param);
int			key_exit(int keycode, t_full_image *full_image);
int			key_map_move(int keycode, t_full_image *param);
/*
**		actions
*/
int			set_color_shift(int keycode, t_full_image *param);
void		set_defaults(t_fractal *fractal, int flag);
int			mouse_motion(int x, int y, t_full_image *full);
void		draw_meme_man(t_full_image *full, int x, int y);
void		get_meme_pos(t_full_image *full, int x, int y);

/*
**		image work
*/
int			fill_menu(t_image **menu);
void		create_img(t_image **image, int x, int y, t_window *local);
void		clear_image(t_image **image, unsigned long size);
void		image_set_pixel(t_image **image, int x, int y, int color);
void		draw(t_full_image *full);
int			open_image(t_image **image, char *filename, int size_x, int size_y);
void		put_mask(t_image **image, int mask, int x, int y);
void		free_img(t_image **image, unsigned long size);
/*
**		error management
*/
int			check_name(char **name, int stop);
void		fractol_error(char *reason);
/*
**		fractal work
*/
int			get_fractal_img(t_draw_fractal *full);
void		draw_fractal(t_draw_fractal *fractol);
/*
**		fractal formulas
*/
int			mandelbrot(t_fractal *mandelbrot);
int			julia(t_fractal *julia);
int			fuck(t_fractal *cock);

#endif
