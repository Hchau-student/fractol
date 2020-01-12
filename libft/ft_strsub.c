/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 22:34:40 by hchau             #+#    #+#             */
/*   Updated: 2019/04/18 22:36:45 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	char	*my_s;
	size_t	i;

	i = 0;
	my_s = (char*)s;
	if (!s)
		return (NULL);
	new = (my_s + start);
	if (len + 1 == 0)
		return (NULL);
	new = (char *)malloc(sizeof(*new) * (len + 1));
	if (!new)
		return (NULL);
	ft_bzero(new, len + 1);
	while (len > i)
		new[i++] = my_s[start++];
	return (new);
}
