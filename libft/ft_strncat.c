/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 21:59:52 by hchau             #+#    #+#             */
/*   Updated: 2019/04/18 22:03:18 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, char const *src, size_t n)
{
	size_t		a;
	size_t		b;
	char		*my_dest;

	my_dest = (char*)dest;
	a = 0;
	b = 0;
	while (my_dest[b])
		b++;
	while (src[a] && n > 0)
	{
		my_dest[b++] = src[a++];
		n--;
	}
	my_dest[b] = '\0';
	return (dest);
}
