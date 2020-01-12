/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:30:27 by hchau             #+#    #+#             */
/*   Updated: 2019/04/22 11:51:37 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, void const *src, size_t n)
{
	size_t			a;
	char			*my_dest;
	const char		*my_src;

	a = 0;
	my_dest = (char *)dest;
	my_src = (char *)src;
	if (my_dest != my_src)
		while (a < n)
		{
			my_dest[a] = my_src[a];
			a++;
		}
	return (dest);
}
