/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 22:12:15 by hchau             #+#    #+#             */
/*   Updated: 2019/04/19 12:15:44 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char		*my_big;
	size_t		a;
	size_t		b;

	a = 0;
	b = 0;
	my_big = (char*)big;
	if (little == my_big || little[a] == '\0')
		return (my_big);
	while (len + 1 > 0 && my_big[b])
	{
		a = 0;
		while (little[a] && my_big[b + a] == little[a] && a < len)
			a++;
		if (little[a] == '\0')
			return (my_big + b);
		b++;
		len--;
	}
	return (NULL);
}
