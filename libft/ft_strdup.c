/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 21:52:49 by hchau             #+#    #+#             */
/*   Updated: 2019/04/22 11:23:26 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *s)
{
	char		*new;
	size_t		n;

	n = 0;
	if (!(new = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[n])
	{
		new[n] = s[n];
		n++;
	}
	new[n] = '\0';
	return (new);
}
