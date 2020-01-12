/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 22:50:09 by hchau             #+#    #+#             */
/*   Updated: 2019/04/21 10:23:15 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, void const *src, int c, size_t n)
{
	unsigned char		*my_dest;
	unsigned char const	*my_src;
	unsigned char		my_c;
	size_t				i;

	my_dest = dest;
	my_src = src;
	my_c = c;
	i = 0;
	while (n > i)
	{
		my_dest[i] = my_src[i];
		if (my_src[i] == my_c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
