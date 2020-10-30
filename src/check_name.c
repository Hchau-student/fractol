/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 11:41:31 by hchau             #+#    #+#             */
/*   Updated: 2020/02/10 11:41:38 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/header.h"
#define J				"Julia"
#define M				"Mandelbrot"
#define BSH				"BurningShip"

int		is_fractal(char *name, t_fractal **fractal)
{
	int						count;
	static t_fractal		valid[FRACTAL_NUM] = {
			{J, 50, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, &julia},
			{M, 50, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, &mandelbrot},
			{BSH, 50, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, &fuck},
			{"-h", 50, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, &julia}
	};

	count = FRACTAL_NUM - 1;
	while (count >= 0)
	{
		if ((ft_strequ(name, valid[count].name)) == TRUE)
		{
			if (count == 3)
				return (HELP);
			*fractal = &valid[count];
			set_defaults(*fractal, ALL);
			return (TRUE);
		}
		count--;
	}
	return (FAULSE);
}

int		check_name(char **name, int stop)
{
	int			i;
	int			res;
	t_fractal	*key;

	i = 1;
	while (i < stop + 1)
	{
		if ((res = is_fractal(name[i], &key)) == TRUE)
			start_the_programm(key);
		if (res == HELP)
			fractol_error(H);
		else
		{
			ft_putstr(name[i]);
			fractol_error(INCORRECT_NAME);
		}
		i++;
	}
	return (0);
}
