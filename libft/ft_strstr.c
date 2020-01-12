/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 22:10:08 by hchau             #+#    #+#             */
/*   Updated: 2019/04/18 22:11:53 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *haystack, char const *needle)
{
	size_t		a;
	size_t		b;

	b = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[b] && (b + 1 != 0))
	{
		a = 0;
		while (haystack[a + b] == needle[a] && needle[a] && (b + 1 != 0))
			a++;
		if (needle[a] == '\0')
			return ((char *)(haystack + b));
		b++;
	}
	return (NULL);
}
