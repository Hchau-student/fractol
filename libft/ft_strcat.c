/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 21:57:40 by hchau             #+#    #+#             */
/*   Updated: 2019/04/18 21:58:56 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, char const *src)
{
	size_t	a;
	size_t	b;
	char	*my_dest;

	my_dest = (char*)dest;
	a = 0;
	b = 0;
	while (my_dest[b])
		b++;
	while (src[a] && b + 1 > 0)
	{
		my_dest[b] = src[a];
		a++;
		b++;
	}
	my_dest[b] = '\0';
	return (dest);
}
