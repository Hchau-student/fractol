/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 11:10:04 by hchau             #+#    #+#             */
/*   Updated: 2019/04/21 11:58:18 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcdup(char const *s, char c)
{
	size_t		count;
	char		*res;

	count = 0;
	while ((s[count] && s[count] != c) && (count + 1 > 0))
		count++;
	res = ft_strnew(count);
	if (!res)
	{
		free(res);
		return (0);
	}
	res = ft_strncpy(res, s, count);
	res[count] = '\0';
	return (res);
}
