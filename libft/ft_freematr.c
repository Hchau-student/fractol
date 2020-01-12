/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freematr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 11:04:01 by hchau             #+#    #+#             */
/*   Updated: 2019/04/23 00:52:24 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_freematr(char **matr)
{
	size_t		i;

	i = 0;
	while (matr[i])
	{
		free(matr[i]);
		matr[i++] = NULL;
	}
	free(matr);
	matr = NULL;
	return (NULL);
}
