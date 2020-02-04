//
// Created by Hugor Chau on 2020-01-15.
//

#ifndef GRAPHIC_STRUCTS_H
#define GRAPHIC_STRUCTS_H

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

//typedef struct		s_coord
//{
//	int				x;
//	int				y;
//	int				z;
//	int				color;
//}					t_coord;

//typedef struct		s_rotation
//{
//	double			x_rot;
//	double			y_rot;
//	double			z_rot;
//}					t_rotation;

#endif
