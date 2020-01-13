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
# include "../incs/fractol_err.h"
# include "keycode_fractol.h"
# include "../libft/libft.h"
# include "mlx.h"
# include <math.h>
# include <pthread.h>

# define CHECK			"you made it!"
# define FAIL			"oh no!"
# define SIZE_MENU		350
# define SIZE_WINDOW_X	1000
# define SIZE_WINDOW_Y	1000
# define TRUE			1
# define FAULSE			0
# define FRACTAL_NUM	2
# define JULIA			0
# define MANDELBROT		1
# define THREADS		10
#define GREEN			0
#define PURPLE			-1
/*
**				int			max_iteration;
**				t_complex	min;
**				t_complex	max;
**				t_complex	k(for Julia);
**				t_complex	c(for formula);
**				t_complex	factor;
**				int			start_line;		для реализации мультипоточности для более быстрой обработки
**				int			finish_line;	для реализации мультипоточности для более быстрой обработки
**				int			color_shift;
*/

# define BEGIN_MEANING	10, {-2.0, -2.0}, {2.0, 2.0}, {-0.4, 0.6}, {0.0, 0.0}, {0.0, 0.0}, 0, 0, 0, 0

typedef struct		s_coord
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_coord;

typedef struct		s_rotation
{
	double			x_rot;
	double			y_rot;
	double			z_rot;
}					t_rotation;

typedef struct		s_complex
{
	double			real;
	double			imagine;
}					t_complex;

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

typedef struct		s_fractal
{
	char 			*name;
	int				max_iteration;
	t_complex		min;
	t_complex		max;
	t_complex		k;
	t_complex		c;
	t_complex		factor;
	int				color_shift;
	int				start_line;
	int				finish_line;
	int				rotate;
	int				(*count_fractal)(struct s_fractal *);
}					t_fractal;

typedef struct		s_full_image
{
	t_image			*menu;
	t_image			*drawing;
	int				menu_on;
	t_window		*ptr;
	t_fractal		fractal;
	t_rotation		rotation;
	t_coord			**z_matrix;
}					t_full_image;

/*
**		programm core
*/
void		start_the_programm(t_fractal *fractal);
/*
**		events
*/
void		manage_processes(t_full_image *full, t_fractal *fractal);
int			key_press(int keycode, t_full_image *param);
int			close_fractol(t_window *param);
int			mouse_scroll(int button, int x, int y, t_full_image *param);
/*
**		image work
*/
int			fill_menu(t_image **menu);
void		create_img(t_image **image, int x, int y, t_window *local);
void		clear_image(t_image **image, unsigned long size);
void		image_set_pixel(t_image **image, int x, int y, int color);

/*
**		error management
*/
int			check_name(char **name, int stop);
void		fractol_error(char *reason);
/*
**		fractal work
*/
int			get_fractal_img(t_full_image *full);
void		draw(t_full_image *full);
int			mandelbrot(t_fractal *mandelbrot);
int			julia(t_fractal *julia);
void		draw_fractal(t_full_image *fractol);
void		rotate_node(t_coord *current, t_rotation rot);
void		img_from_matrix(t_image **image, t_coord **z_matrix);
void	rotate_all(t_coord ***z_matrix, t_rotation rot);

#endif
