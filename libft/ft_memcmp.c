/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 21:49:00 by hchau             #+#    #+#             */
/*   Updated: 2019/04/18 21:51:05 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(void const *s1, void const *s2, size_t n)
{
	char	*my_s1;
	char	*my_s2;
	size_t	a;

	my_s1 = (char*)s1;
	my_s2 = (char*)s2;
	a = 0;
	if (n == 0)
		return (0);
	while (--n > 0)
		if (my_s1[a] == my_s2[a])
			a++;
	return ((unsigned char)my_s1[a] - (unsigned char)my_s2[a]);
}
