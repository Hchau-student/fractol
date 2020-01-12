/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 22:08:33 by hchau             #+#    #+#             */
/*   Updated: 2019/04/22 11:20:45 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *s, int c)
{
	size_t		a;
	char		*my_s;

	my_s = (char *)s;
	a = 0;
	while (my_s[a] && a + 1 > 0)
		a++;
	while (a > 0 && my_s[a] != c)
		a--;
	if (my_s[a] == c)
		return (my_s + a);
	return (NULL);
}
