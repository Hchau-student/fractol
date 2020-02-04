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

int		main(int ac, char **check)
{
	if (ac < 2)
		fractol_error(MISSING_NAME);
	check_name(check, ac);
//	my_pow(2.899988898898989);
	return (0);
}
