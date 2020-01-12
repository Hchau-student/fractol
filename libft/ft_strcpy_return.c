/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_return.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflannel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 19:01:11 by mflannel          #+#    #+#             */
/*   Updated: 2019/12/16 19:01:21 by mflannel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy_return(char *dest, char const *src)
{
	size_t		a;
	size_t		len;

	a = 0;
	if (dest != src)
	{
		len = ft_strlen(src);
		while (src[a] && a < len)
		{
			dest[a] = src[a];
			a++;
		}
		dest[a] = '\0';
	}
	return (dest + a);
}
