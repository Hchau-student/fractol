/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:12:04 by hchau             #+#    #+#             */
/*   Updated: 2019/04/12 21:12:29 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*my_null;
	size_t	i;

	my_null = (char *)s;
	i = 0;
	while (i < n)
		my_null[i++] = (unsigned char)c;
	return ((void *)s);
}
