/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_one_delim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 23:42:12 by hchau             #+#    #+#             */
/*   Updated: 2019/04/23 23:49:28 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_one_delim(char const *s, char c)
{
	char	*temp;
	char	*spaces;
	int		i;

	temp = (char *)s;
	i = ft_strlen(s);
	while (*temp)
	{
		if (!(ft_strrchr(temp, c)))
			break ;
		spaces = ft_memchr(temp++, c, i);
		if (spaces[0] == spaces[1])
			temp = ft_memmove((spaces), (spaces + 1), i);
	}
}
