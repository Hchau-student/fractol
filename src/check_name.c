//
// Created by Hugor Chau on 2020-01-11.
//

#include "../incs/header.h"

int		is_fractal(char *name, t_fractal **fractal)
{
	int 			count;
	static t_fractal		valid[FRACTAL_NUM] = {
			{"Julia", BEGIN_MEANING, &julia, TRUE},
			{"Mandelbrot", BEGIN_MEANING, &mandelbrot, TRUE},
			{"Хуй", BEGIN_MEANING, &fuck, TRUE},
			{"Cock", BEGIN_MEANING, &fuck, TRUE}
	};

	count = FRACTAL_NUM - 1;
	while (count >= 0)
	{
		if ((ft_strequ(name, valid[count].name)) == TRUE)
		{
			*fractal = &valid[count];
//			(*fractal)->max.imagine = (*fractal)->min.imagine
//					+ ((*fractal)->max.real
//					- (*fractal)->min.real) * SIZE_WINDOW_Y / SIZE_WINDOW_X;
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
			start_the_programm(key);
		}
		else
			fractol_error(INCORRECT_NAME);
		i++;
	}
	return (0);
}
