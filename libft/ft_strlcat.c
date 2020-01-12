/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 22:03:52 by hchau             #+#    #+#             */
/*   Updated: 2019/04/21 10:22:08 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char const *src, size_t size)
{
	size_t		a;
	size_t		i;
	size_t		j;
	char		*my_dest;

	my_dest = (char*)dest;
	a = 0;
	if (size <= ft_strlen(dest))
		return (ft_strlen(src) + size);
	i = ft_strlen(dest) + ft_strlen(src);
	j = 0;
	while (my_dest[j] && size-- > 0)
		j++;
	if (size != 0)
	{
		while ((src[a] && --size > 0) && j + 1 > 0)
			my_dest[j++] = src[a++];
	}
	my_dest[j] = '\0';
	return (i);
}
