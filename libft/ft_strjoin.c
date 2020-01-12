/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 21:02:31 by hchau             #+#    #+#             */
/*   Updated: 2019/04/11 19:34:39 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		j;
	char		*new;

	if (!s1 || !s2)
		return (0);
	j = ft_strlen(s1);
	i = ft_strlen(s2);
	if ((i + j < i) || (i + j) < j)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(new = ft_strnew(i + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
		new[i++] = s2[j++];
	return (new);
}
