/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 23:21:08 by hchau             #+#    #+#             */
/*   Updated: 2019/04/18 21:45:12 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void const *src, size_t n)
{
	size_t			a;
	char			*my_dest;
	char			*my_src;

	my_dest = (char*)dest;
	my_src = (char*)src;
	a = 0;
	if (my_dest > my_src)
		while (n-- > 0)
			my_dest[n] = my_src[n];
	else if (my_dest < my_src)
		while (n > a)
		{
			my_dest[a] = my_src[a];
			a++;
		}
	return (dest);
}
