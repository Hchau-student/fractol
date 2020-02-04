//
// Created by Hugor Chau on 2020-01-11.
//

#include "../incs/header.h"

int		is_fractal(char *name, t_fractal **fractal)
{
	int 			count;
	static t_fractal		valid[FRACTAL_NUM] = {
			{"Julia", DEFAULT_ITERATIONS, JULIA_DEFAULT_K,
				DEFAULT_COMPLEX, &julia},
			{"Mandelbrot", DEFAULT_ITERATIONS, DEFAULT_K,
				DEFAULT_COMPLEX, &mandelbrot},
			{"Хуй", DEFAULT_ITERATIONS, DEFAULT_K,
					DEFAULT_COMPLEX, &fuck}
	};

	count = FRACTAL_NUM - 1;
	while (count >= 0)
	{
		if ((ft_strequ(name, valid[count].name)) == TRUE)
		{
			*fractal = &valid[count];
//			(*fractal)->max.y = (*fractal)->min.y
//					+ ((*fractal)->max.x
//					- (*fractal)->min.x) * SIZE_WINDOW_Y / SIZE_WINDOW_X;
			return (TRUE);
		}
		count--;
	}
	return (FAULSE);
}

int		check_name(char **name, int stop)
{
	int			i;
	t_fractal	*key;

	i = 1;
	while (i < stop + 1)
	{
		if ((is_fractal(name[i], &key)) == TRUE)
		{
//			if ()
			start_the_programm(key);
		}
		else
			fractol_error(INCORRECT_NAME);
		i++;
	}
	return (0);
}
