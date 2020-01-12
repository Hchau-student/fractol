/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 21:46:16 by hchau             #+#    #+#             */
/*   Updated: 2019/04/18 21:48:12 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *s, int c, size_t n)
{
	char		*char_s;
	size_t		i;

	i = 0;
	char_s = (char*)s;
	while (n-- > 0)
	{
		if ((unsigned char)char_s[i] == (unsigned char)c)
			return ((void *)(char_s + i));
		i++;
	}
	return (NULL);
}
