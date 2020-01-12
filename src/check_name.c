//
// Created by Hugor Chau on 2020-01-11.
//

#include "../incs/header.h"

int		is_fractal(char *name, t_fractal **fractal)
{
	static t_fractal		valid[FRACTAL_NUM] = {
			{"Julia", BEGIN_MEANING},
			{"Mandelbrot", BEGIN_MEANING}
	};
	int 			count;

	count = FRACTAL_NUM - 1;
	while (count >= 0)
	{
		if ((ft_strequ(name, valid[count].name)) == TRUE)
		{
			*fractal = &valid[count];
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