/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 10:10:31 by hchau             #+#    #+#             */
/*   Updated: 2019/12/28 10:10:33 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/header.h"

void		fractol_error(char *reason)
{
	if (ft_strequ(reason, H))
	{
		ft_putstr(H1);
		ft_putstr(H2);
		ft_putstr(H3);
		ft_putstr(H4);
		ft_putstr(H5);
		ft_putstr(H6);
	}
	else
		ft_putstr(reason);
	ft_putstr(USAGE);
	exit(0);
}

int			main(int ac, char **check)
{
	if (ac < 2)
		fractol_error(MISSING_NAME);
	if (ac > 2)
		fractol_error(TOO_MUCH);
	check_name(check, ac);
	return (0);
}
