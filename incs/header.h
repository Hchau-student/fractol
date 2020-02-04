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

#ifndef FRACTOL_H
# define FRACTOL_H
# include "fractol_err.h"
# include "keycode_fractol.h"
# include "local_structs.h"
# include "../libft/libft.h"
# include "mlx.h"
# include <math.h>
# include <pthread.h>
# include <OpenCL/opencl.h>

# define CHECK			"you made it!"
# define FAIL			"oh no!"
# define SIZE_MENU		350
# define SIZE_WINDOW_X	1000
# define SIZE_WINDOW_Y	1000
# define TRUE			1
# define FAULSE			0
# define FRACTAL_NUM	3
# define THREADS		10
# define ALL			1
# define POSITION		0
/*
**				int			max_iteration;
**				t_complex	min;
**				t_complex	max;
**				t_complex	k(for Julia);
**				t_complex	constant(for formula);
**				t_complex	current;
**				int			color_shift;
*/

# define DEFAULT_ITERATIONS		50
# define JULIA_DEFAULT_K		{0.4, 0.1}
# define DEFAULT_K				{0.0, 0.0}
# define DEFAULT_COMPLEX 		{-2.0, -2.0}, {2.0, 2.0}, {0.0, 0.0}, {0.0, 0.0}

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
int			close_fractol(t_window *param);
int			mouse_scroll(int button, int x, int y, t_full_image *param);
int			mouse_motion(int x, int y, t_full_image *full);
int			key_stop_k_move(int keycode, t_full_image *param);
/*
**		key press
*/
int			key_patrick(int keycode, t_full_image *param);
int			key_default(int keycode, t_full_image *param);
int			key_menu(int keycode, t_full_image *param);
int			key_stop_k_move(int keycode, t_full_image *param);
int			key_rotate(int keycode, t_full_image *param);
int			key_exit(int keycode, t_full_image *full_image);
int			key_map_move(int keycode, t_full_image *param);
/*
**		actions
*/
int			set_color_shift(int keycode, t_full_image *param);
void		set_defaults(t_fractal *fractal, int flag);
int			close_fractal(t_window *param);
/*
**		image work
*/
int			fill_menu(t_image **menu);
void		create_img(t_image **image, int x, int y, t_window *local);
void		clear_image(t_image **image, unsigned long size);
void		image_set_pixel(t_image **image, int x, int y, int color);
void		draw(t_full_image *full);
void		open_image(t_image **image, char *filename, int size_x, int size_y);
void		put_mask(t_image **image, int mask, int x, int y);
/*
**		error management
*/
int			check_name(char **name, int stop);
void		fractol_error(char *reason);
/*
**		fractal work
*/
int			get_fractal_img(t_draw_fractal *full);
int			mandelbrot(t_fractal *mandelbrot);
//void		rotate_node(t_coord *current, t_rotation rot);?
//void		img_from_matrix(t_image **image, t_coord **z_matrix);?
//void		rotate_all(t_coord ***z_matrix, t_rotation rot);?
/*
**		fractal formulas
*/
int			julia(t_fractal *julia);
void		draw_fractal(t_draw_fractal *fractol);
int			fuck(t_fractal *cock);

#endif
