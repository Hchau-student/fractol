/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 10:24:32 by hchau             #+#    #+#             */
/*   Updated: 2019/04/22 11:09:17 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getsize(char const *s, char c)
{
	size_t		size;
	size_t		count;

	size = 0;
	count = 0;
	while ((s && s[count]) && (count + 1) > 0)
	{
		while (s[count] && s[count] == c)
			count++;
		if (s[count] && s[count] != c)
		{
			while (s[count] && s[count] != c)
				count++;
			size++;
		}
	}
	return (size);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		word;
	char		**matr;

	if (!s)
		return (NULL);
	if (!(matr = (char**)malloc(sizeof(char*) * (ft_getsize(s, c) + 1))))
		return (0);
	word = 0;
	while (*s)
	{
		if (*s && *s != c)
		{
			matr[word] = ft_strcdup(s, c);
			if (!matr[word])
				return (ft_freematr(matr));
			while (*(s + 1) && *(s + 1) != c)
				s++;
			word++;
		}
		s++;
	}
	matr[word] = NULL;
	return (matr);
}
