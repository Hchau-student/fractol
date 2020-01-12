/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 22:30:26 by hchau             #+#    #+#             */
/*   Updated: 2019/04/19 15:13:25 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		b;
	char		*res;

	if (s)
	{
		while (*s == ' ' || *s == '\n' || *s == '\t')
			s++;
		b = ft_strlen(s);
		if (b <= 1)
			return (ft_strnew(0));
		while (s[b - 1] == ' ' || s[b - 1] == '\n' || s[b - 1] == '\t')
			--b;
		res = ft_strnew(b);
		if (!res)
			return (0);
		ft_strncpy(res, s, b);
		return (res);
	}
	return (0);
}
